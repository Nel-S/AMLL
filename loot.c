#include "loot.h"
#include <string.h>

bool initializeLootTable(LootTable *const lootTable, enum Source source, enum Version version, enum Biome biome) {
	// Cannot continue if a loot table was not provided
	if (!lootTable) return false;
	// Attempt to allocate pools array
	lootTable->source = source;
	lootTable->version = version;
	/* For 1.4.6 - 1.8.9 (or monster rooms 1.6.4 - 1.8.9), the enchantment for enchanted books is rolled prior to everything else.
	   We store the list of possible enchantments in the loot table beforehand.*/
	lootTable->pre1_9EnchantmentsCount = getAttributesCapacity(-1, 0, source, version, biome);
	if (lootTable->pre1_9EnchantmentsCount) {
		lootTable->pre1_9Enchantments = (Attribute *)calloc(lootTable->pre1_9EnchantmentsCount, sizeof(Attribute));
		copyEnchantments(lootTable->pre1_9Enchantments, lootTable->pre1_9EnchantmentsCount, -1, 0, source, version, biome);
	}
	lootTable->poolCount = getPoolCount(source, version, biome);
	if (!lootTable->poolCount) return false;
	lootTable->pools = (LootPool *)calloc(lootTable->poolCount, sizeof(LootPool));
	if (!lootTable->pools) return false;
	// For each pool, attempt to allocate loot items array
	for (size_t p = 0; p < lootTable->poolCount; ++p) {
		lootTable->pools[p].entryCount = getEntryCount(p, source, version, biome);
		if (!lootTable->pools[p].entryCount) return false;
		lootTable->pools[p].entries = (LootEntry *)calloc(lootTable->pools[p].entryCount, sizeof(LootEntry));
		if (!lootTable->pools[p].entries) return false;
		// For each entry, attempt to allocate attributes array
		for (size_t e = 0; e < lootTable->pools[p].entryCount; ++e) {
			lootTable->pools[p].entries[e].possibleAttributeCapacity = getAttributesCapacity(p, e, source, version, biome);
			if (!lootTable->pools[p].entries[e].possibleAttributeCapacity) continue;
			lootTable->pools[p].entries[e].possibleAttributes = (Attribute *)calloc(lootTable->pools[p].entries[e].possibleAttributeCapacity, sizeof(Attribute));
			if (!lootTable->pools[p].entries[e].possibleAttributes) return false;
		}
	}
	// Then add actual loot to the table
	return addLootToTable(lootTable, source, version, biome);
}

bool initializeOutputArray(Item *const outputArray, size_t outputArrayCapacity) {
	if (!outputArray || !outputArrayCapacity) return false;
	for (size_t i = 0; i < outputArrayCapacity; ++i) outputArray[i].attributesCapacity = 0;
	return true;
}

ssize_t getLoot(const LootTable *const lootTable, uint64_t lootSeed, Item *const output, size_t outputCapacity) {
	// If no loot table, output, or pools-in-loot-table were provided, loot cannot be emulated
	if (!lootTable || !output || !lootTable->pools) return -1;
	// If the output array has 0 capacity, nothing can be returned
	if (!outputCapacity) return 0;
	// Seed PRNG
	PRNG prng;
	prng.type = lootTable->prngType;
	abstractSetSeed(&prng, lootSeed, 0);
	size_t outputSize = 0;
	/* We have to construct the item-to-be-placed separately, then deep-copy it into the chosen slot, to account for the facts that A. we don't
	   know the slot until the very end and B. the output could potentially already be completely full (i.e. there's no spare space to work in).*/
	Item currentItem;
	currentItem.attributesCapacity = 0;
	// Precompute enchantment if relevant
	Attribute *chosenEnchantment = lootTable->pre1_9EnchantmentsCount ? &lootTable->pre1_9Enchantments[abstractNextInt(&prng, lootTable->pre1_9EnchantmentsCount)] : NULL;
	int chosenLevel = chosenEnchantment ? (chosenEnchantment->level + (chosenEnchantment->level < chosenEnchantment->maxLevel ? abstractNextInt(&prng, chosenEnchantment->maxLevel - chosenEnchantment->level + 1) : 0)) : 0;
	// For each pool:
	for (size_t p = 0; p < lootTable->poolCount; ++p) {
		const LootPool *const pool = &lootTable->pools[p];
		if (!pool->entries || !pool->entryCount) return -1;
		// Determine number of rolls to perform for current pool
		int rolls = pool->minRolls;
		if (pool->minRolls < pool->maxRolls) rolls += abstractNextInt(&prng, pool->maxRolls - pool->minRolls + 1);
		// 1.5-1.8.9 mineshafts have an extra nextBoolean while placing the minecart-with-chest
		if (lootTable->source == Source_Mineshaft && lootTable->version >= Version_1_5 && lootTable->version < Version_1_9) abstractNextInt(&prng, 2);
		// For each roll:
		for (int r = 0; r < rolls; ++r) {
			// Select an entry
			int selection = abstractNextInt(&prng, pool->summedWeight);
			size_t e = 0;
			while (e < pool->entryCount && pool->entries[e].weight <= selection) {
				selection -= pool->entries[e].weight;
				++e;
			}
			if (selection < 0) continue; // This can happen if entryCount != the count of all entries, or summedWeight != the sum of all weights
			const LootEntry *const entry = &pool->entries[e];
			// TODO: I doubt additional calculations are done when the selected item is air, but check
			if (entry->type == Item_None) continue;
			// If additional rarity checks exist, perform those
			if (entry->rarity > 1) {
				if (abstractNextInt(&prng, entry->rarity)) continue;
			}
			// Store output type
			currentItem.type = entry->type;
			// Calculate and store output count
			currentItem.count = entry->minCount;
			// Prior to 1.9 (excluding monster rooms pre-1.6.1), this was always rolled even if minCount == maxCount
			if ((lootTable->version < Version_1_9 && (lootTable->source != Source_Monster_Room || lootTable->version >= Version_1_6_1)) || entry->minCount < entry->maxCount) currentItem.count += abstractNextInt(&prng, entry->maxCount - entry->minCount + 1);
			// Determine number of attributes to add to current item
			currentItem.attributeCount = entry->minPossibleAttributes;
			if (entry->minPossibleAttributes < entry->maxPossibleAttributes) currentItem.attributeCount += abstractNextInt(&prng, entry->maxPossibleAttributes - entry->minPossibleAttributes + 1);
			// If nonzero, and if output hadn't previously allocated memory for attributes, do so
			if (currentItem.attributesCapacity < (size_t)currentItem.attributeCount) {
				if (!currentItem.attributesCapacity) currentItem.attributes = (Attribute *)calloc(currentItem.attributeCount, sizeof(Attribute));
				else currentItem.attributes = (Attribute *)realloc(currentItem.attributes, sizeof(Attribute)*currentItem.attributeCount);
				if (!currentItem.attributes) return -1;
				currentItem.attributesCapacity = (size_t)currentItem.attributeCount;
			}
			// For each attribute to add:
			for (int a = 0; a < currentItem.attributeCount; ++a) {
				if (entry->type == Item_Enchanted_Book && chosenEnchantment) {
					if (!copyAttribute(chosenEnchantment, &currentItem.attributes[a])) return -1;
					currentItem.attributes[a].level = chosenLevel;
					continue;
				}
				// Choose the attribute, copy it
				if (!entry->possibleAttributeCapacity) return -1;
				// TODO: Picking enchantments becomes more complicated than this in 1.7.2
				int s = entry->possibleAttributeCapacity > 1 ? abstractNextInt(&prng, (int)entry->possibleAttributeCapacity) : 0;
				if (!copyAttribute(&entry->possibleAttributes[s], &currentItem.attributes[a])) return -1;
				if (currentItem.attributes[a].level < currentItem.attributes[a].maxLevel) currentItem.attributes[a].level += abstractNextInt(&prng, currentItem.attributes[a].maxLevel - currentItem.attributes[a].level + 1);
			}
			/* Calculate and store chest indices.
			   From Infdev 20100625-1917 through at least 1.6.4, if any previous items were already placed in that slot, they are overwritten.
			   TODO: Do any versions instead discard the current item?*/
			int remainingCount = 1;
			if ((lootTable->source != Source_Monster_Room || Version_1_6_1 <= lootTable->version) && getMaxStackCount(currentItem.type, lootTable->version) < currentItem.count) {
				remainingCount = currentItem.count;
				currentItem.count = 1;
			}
			for (; remainingCount > 0; --remainingCount) {
				currentItem.containerIndex = abstractNextInt(&prng, (int)lootTable->containerCapacity);
				size_t outputIndex;
				// This extra looping could be eliminated if we replaced the output with an unordered map.
				for (outputIndex = 0; outputIndex < outputSize && output[outputIndex].containerIndex != currentItem.containerIndex; ++outputIndex);
				if (outputCapacity <= outputIndex || !copyItem(&currentItem, &output[outputIndex])) return -1; // First condition shouldn't be possible
				if (outputSize <= outputIndex) outputSize = outputIndex + 1;
			}
		}
	}
	return outputSize;
}

bool freeLootTable(LootTable *const lootTable) {
	// If no loot table was provided, it cannot be freed
	if (!lootTable) return false;
	// If the loot table's pools were never initialized, there is nothing more to do
	if (!lootTable->pools) return true;
	for (size_t p = 0; p < lootTable->poolCount; ++p) {
		// If the loot pool's items were never initialized, there is nothing to do
		if (!lootTable->pools[p].entries) continue;
		free(lootTable->pools[p].entries);
	}
	free(lootTable->pools);
	return true;
}

bool freeOutputArray(Item *const outputArray, size_t outputArrayCapacity) {
	// If no output was provided, it cannot be freed
	if (!outputArray || !outputArrayCapacity) return false;
	for (size_t o = 0; o < outputArrayCapacity; ++o) {
		// If the current item's attributes were never initialized, there is nothing to do
		if (!outputArray[o].attributes || !outputArray[o].attributesCapacity) continue;
		free(outputArray[o].attributes);
	}
	return true;
}