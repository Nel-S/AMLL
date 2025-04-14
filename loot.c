#include "loot.h"
#include <string.h>

bool initializeLootTable(LootTable *const lootTable, enum Source source, enum Version version, enum Biome biome) {
	// Cannot continue if a loot table was not provided
	if (!lootTable) return false;
	// Attempt to allocate pools array
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
	ssize_t outputSize = 0;
	// For each pool:
	for (size_t p = 0; p < lootTable->poolCount; ++p) {
		const LootPool *const pool = &lootTable->pools[p];
		if (!pool->entries || !pool->entryCount) return -1;
		// Determine number of rolls to perform for current pool
		int rolls = pool->minRolls;
		if (pool->minRolls < pool->maxRolls) rolls += abstractNextInt(&prng, pool->maxRolls - pool->minRolls + 1);
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
			output[outputSize].type = entry->type;
			// Calculate and store output count
			output[outputSize].count = entry->minCount;
			if (entry->minCount < entry->maxCount) output[outputSize].count += abstractNextInt(&prng, entry->maxCount - entry->minCount + 1);
			// Determine number of attributes to add to current item
			output[outputSize].attributeCount = entry->minPossibleAttributes;
			if (entry->minPossibleAttributes < entry->maxPossibleAttributes) output[outputSize].attributeCount += abstractNextInt(&prng, entry->maxPossibleAttributes - entry->minPossibleAttributes + 1);
			// If nonzero, and if output hadn't previously allocated memory for attributes, do so
			if (output[outputSize].attributesCapacity < (size_t)output[outputSize].attributeCount) {
				if (!output[outputSize].attributesCapacity) output[outputSize].attributes = (Attribute *)calloc(output[outputSize].attributeCount, sizeof(Attribute));
				else output[outputSize].attributes = (Attribute *)realloc(output[outputSize].attributes, sizeof(Attribute)*output[outputSize].attributeCount);
				if (!output[outputSize].attributes) return -1;
				output[outputSize].attributesCapacity = (size_t)output[outputSize].attributeCount;
			}
			// For each attribute to add:
			for (int a = 0; a < output[outputSize].attributeCount; ++a) {
				int s = abstractNextInt(&prng, (int)entry->possibleAttributeCapacity);
				const Attribute *const attribute = &entry->possibleAttributes[s];
				output[outputSize].attributes[a].name = attribute->name;
				output[outputSize].attributes[a].level = attribute->level;
				if (attribute->level < attribute->maxLevel) output[outputSize].attributes[a].level += abstractNextInt(&prng, attribute->maxLevel - attribute->level + 1);
				output[outputSize].attributes[a].maxLevel = output[outputSize].attributes[a].level;
			}
			// Calculate and store chest index
			output[outputSize].containerIndex = abstractNextInt(&prng, (int)lootTable->containerCapacity);

			// From Infdev 20100625-1917 through at least 1.4.5, if any previous items were already placed in that slot, they are overwritten.
			// TODO: Do any versions instead discard the current item?
			int shift = 0;
			for (int o = 0; o <= outputSize; ++o) {
				if (shift) {
					if (output[o].attributeCount > 0) {
						if (output[o - shift].attributeCount <= 0) output[o - shift].attributes = (Attribute *)calloc(output[o].attributeCount, sizeof(Attribute));
						else if (output[o - shift].attributeCount < output[o].attributeCount) output[o - shift].attributes = (Attribute *)realloc(output[o - shift].attributes, sizeof(Attribute)*output[o].attributeCount);
						if (!output[o - shift].attributes) break;
						memcpy(output[o - shift].attributes, output[o].attributes, sizeof(Attribute)*output[o].attributeCount);
					}
					output[o - shift].attributeCount = output[o].attributeCount;
					output[o - shift].containerIndex = output[o].containerIndex;
					output[o - shift].count = output[o].count;
					output[o - shift].type = output[o].type;
				}
				if (output[o].containerIndex == output[outputSize].containerIndex && o != outputSize) ++shift;
			}

			// Update size; abort early if output is full
			outputSize += 1 - shift;
			if (outputSize >= (ssize_t)outputCapacity) return outputCapacity;
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