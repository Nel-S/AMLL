#include "loot.h"

bool initializeLootTable(LootTable *const lootTable, enum Structure structure, enum Version version, enum Biome biome) {
	// Cannot continue if a loot table was not provided
	if (!lootTable) return false;
	// Attempt to allocate pools array
	lootTable->poolCount = getPoolCount(structure, version, biome);
	if (!lootTable->poolCount) return false;
	lootTable->pools = (LootPool *)calloc(lootTable->poolCount, sizeof(LootPool));
	if (!lootTable->pools) return false;
	// For each pool, attempt to allocate loot items array
	for (size_t i = 0; i < lootTable->poolCount; ++i) {
		lootTable->pools[i].entryCount = getEntryCount(i, structure, version, biome);
		if (!lootTable->pools[i].entryCount) return false;
		lootTable->pools[i].entries = (LootEntry *)calloc(lootTable->pools[i].entryCount, sizeof(LootEntry));
		if (!lootTable->pools[i].entries) return false;
	}
	// Then add actual loot to the table
	return addLootToTable(lootTable, structure, version, biome);
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
		if (!lootTable->pools[p].entries) return -1;
		// Determine number of rolls to perform for current pool
		int rolls = lootTable->pools[p].minRolls;
		if (lootTable->pools[p].minRolls < lootTable->pools[p].maxRolls) rolls += abstractNextInt(&prng, lootTable->pools[p].maxRolls - lootTable->pools[p].minRolls + 1);
		// For each roll:
		for (int r = 0; r < rolls; ++r) {
			int selection = abstractNextInt(&prng, lootTable->pools[p].summedWeight);
			size_t i = 0;
			while (i < lootTable->pools[p].entryCount && lootTable->pools[p].entries[i].weight <= selection) {
				selection -= lootTable->pools[p].entries[i].weight;
				++i;
			}
			// This can happen if entryCount != the count of all entries, or summedWeight != the sum of all weights
			if (selection < 0) continue;
			// TODO: I doubt additional calculations are done when the selected item is air, but check
			if (lootTable->pools[p].entries[i].type == Item_None) continue;
			// If additional rarity checks exist, perform those
			if (lootTable->pools[p].entries[i].rarity > 1) {
				if (abstractNextInt(&prng, lootTable->pools[p].entries[i].rarity)) continue;
			}
			// Store output type
			output[outputSize].type = lootTable->pools[p].entries[i].type;
			// Calculate and store output count
			output[outputSize].count = lootTable->pools[p].entries[i].minCount;
			if (lootTable->pools[p].entries[i].minCount < lootTable->pools[p].entries[i].maxCount) output[outputSize].count += abstractNextInt(&prng, lootTable->pools[p].entries[i].maxCount - lootTable->pools[p].entries[i].minCount + 1);
			// If relevant, calculate and store output attributes
			if (lootTable->pools[p].entries[i].setAttributes) lootTable->pools[p].entries[i].setAttributes(&output[outputSize], &prng);
			output[outputSize].chestIndex = abstractNextInt(&prng, MAX_CHEST_CAPACITY);

			// TODO: Check if any previous items were already placed in that slot. In Infdev 20100625-1917, those previous items were overwritten.
			// Other versions might instead skip the current item?

			// Update size; abort early if output is full
			++outputSize;
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
	for (size_t i = 0; i < lootTable->poolCount; ++i) {
		// If the loot pool's items were never initialized, there is nothing to do
		if (!lootTable->pools[i].entries) continue;
		free(lootTable->pools[i].entries);
	}
	free(lootTable->pools);
	return true;
}

// bool freeOutput(Item *const output, size_t outputCapacity) {
// 	// If no output was provided, it cannot be freed
// 	if (!output) return false;
// 	for (size_t i = 0; i < outputCapacity; ++i) {
// 		// If the current item's attributes were never initialized, there is nothing to do
// 		if (!output[i].attributes || !output[i].attributesCount) continue;
// 		free(output[i].attributes);
// 	}
// 	return true;
// }