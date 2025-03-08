#include "loot.h"

bool constructLootTable(int structure, int version, int biome, LootTable *const lootTable) {
	(void)biome;
	if (!lootTable) return false;
	switch (structure) {
		case Structure_Monster_Room:
			if (version < Infdev_20100625_1917) return false;
			lootTable->rngType = RNG_java_util_Random;
			if (!(lootTable->poolsCount = resizeArray(lootTable->pools, 1, sizeof(LootPool), true))) return false;
				// Pool 0
				lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 1;
				if (!(lootTable->pools[0].lootItemsCount = resizeArray(lootTable->pools[0].lootItems, 8, sizeof(LootItem), true))) return false;
				lootTable->pools[0].summedWeight = 10;
				printf("Array resized. New size %zd\n", lootTable->pools[0].lootItemsCount);
				printf("%p\n", (void *)lootTable->pools[0].lootItems);
				printf("%zd\n", sizeof(lootTable->pools[0].lootItems[0]));
					// Item 1
					lootTable->pools[0].lootItems[0].type = Item_Saddle;
					printf("This??\n");
					lootTable->pools[0].lootItems[0].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
					lootTable->pools[0].lootItems[0].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[0].setAttributes = NULL;
					// Item 2
					lootTable->pools[0].lootItems[1].type = Item_Iron_Ingot;
					lootTable->pools[0].lootItems[1].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 4;
					lootTable->pools[0].lootItems[1].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[1].setAttributes = NULL;
					// Item 3
					lootTable->pools[0].lootItems[2].type = Item_Bread;
					lootTable->pools[0].lootItems[2].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
					lootTable->pools[0].lootItems[2].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[2].setAttributes = NULL;
					// Item 4
					lootTable->pools[0].lootItems[3].type = Item_Wheat;
					lootTable->pools[0].lootItems[3].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 4;
					lootTable->pools[0].lootItems[3].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[3].setAttributes = NULL;
					// Item 5
					lootTable->pools[0].lootItems[4].type = Item_Gunpowder;
					lootTable->pools[0].lootItems[4].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 4;
					lootTable->pools[0].lootItems[4].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[4].setAttributes = NULL;
					// Item 6
					lootTable->pools[0].lootItems[5].type = Item_String;
					lootTable->pools[0].lootItems[5].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 4;
					lootTable->pools[0].lootItems[5].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[5].setAttributes = NULL;
					// Item 7
					lootTable->pools[0].lootItems[6].type = Item_Bucket;
					lootTable->pools[0].lootItems[6].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
					lootTable->pools[0].lootItems[6].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[6].setAttributes = NULL;
					// Item 8
					lootTable->pools[0].lootItems[7].type = Item_Golden_Apple;
					lootTable->pools[0].lootItems[7].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
					lootTable->pools[0].lootItems[7].weight = 1, lootTable->pools[0].lootItems[0].rarity = 100;
					lootTable->pools[0].lootItems[7].setAttributes = NULL;
			if (version < Alpha_1_0_1) return true;
				printf("This\n");
				if (!(lootTable->pools[0].lootItemsCount = resizeArray(lootTable->pools[0].lootItems, 9, sizeof(LootItem), false))) return false;
				printf("Array resized. New size %zd\n", lootTable->pools[0].lootItemsCount);
				printf("%d\n", !!lootTable->pools[0].lootItems);
				// Total weight increased
				lootTable->pools[0].summedWeight = 11;
					// Item 9
					lootTable->pools[0].lootItems[8].type = Item_Redstone;
					lootTable->pools[0].lootItems[8].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 4;
					lootTable->pools[0].lootItems[8].weight = 1, lootTable->pools[0].lootItems[0].rarity = 2;
					lootTable->pools[0].lootItems[8].setAttributes = NULL;
			if (version < Alpha_1_0_14) return true;
				if (!(lootTable->pools[0].lootItemsCount = resizeArray(lootTable->pools[0].lootItems, 10, sizeof(LootItem), false))) return false;
					// Item 10
					lootTable->pools[0].lootItems[9].type = Item_Music_Disc;
					lootTable->pools[0].lootItems[9].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
					lootTable->pools[0].lootItems[9].weight = 1, lootTable->pools[0].lootItems[0].rarity = 2;
					lootTable->pools[0].lootItems[9].setAttributes = lootAttributes_discType;
			if (version < Beta_1_4) return true;
				if (!(lootTable->pools[0].lootItemsCount = resizeArray(lootTable->pools[0].lootItems, 11, sizeof(LootItem), false))) return false;
					// Item 11
					lootTable->pools[0].lootItems[10].type = Item_Cocoa_Beans;
					lootTable->pools[0].lootItems[10].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
					lootTable->pools[0].lootItems[10].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
					lootTable->pools[0].lootItems[10].setAttributes = NULL;
			return true;
		default: return false;
	}
}

bool freeLootTable(LootTable *const lootTable) {
	// If no loot table was provided, it cannot be freed
	if (!lootTable) return false;
	// If the loot table's pools were never initialized, there is nothing more to do
	if (!lootTable->pools) return true;
	for (size_t i = 0; i < lootTable->poolsCount; ++i) {
		// If the loot pool's items were never initialized, there is nothing to do
		if (!lootTable->pools[i].lootItems) continue;
		free(lootTable->pools[i].lootItems);
	}
	free(lootTable->pools);
	return true;
}

ssize_t getLoot(const LootTable *const lootTable, uint64_t lootSeed, Item *const output, size_t outputCapacity) {
	if (!lootTable || !output || !lootTable->pools) return -1;
	if (!outputCapacity) return 0;
	RNG rng;
	rng.type = lootTable->rngType;
	generalizedSetSeed(&rng, lootSeed, 0);
	ssize_t outputSize = 0;
	// For each pool:
	for (size_t p = 0; p < lootTable->poolsCount; ++p) {
		if (!lootTable->pools[p].lootItems) return -1;
		// Determine number of rolls to perform for current pool
		int rolls = lootTable->pools[p].minRolls;
		if (lootTable->pools[p].minRolls < lootTable->pools[p].maxRolls) rolls += generalizedNextInt(&rng, lootTable->pools[p].maxRolls - lootTable->pools[p].minRolls + 1);
		// For each roll:
		for (int r = 0; r < rolls; ++r) {
			int selection = generalizedNextInt(&rng, lootTable->pools[p].summedWeight);
			size_t i = 0;
			while (i < lootTable->pools[p].lootItemsCount && lootTable->pools[p].lootItems[i].weight <= selection) {
				++i;
				selection -= lootTable->pools[p].lootItems[i].weight;
			}
			// This can happen if lootItemsCount was not truly the count of all lootItems, or summedWeight was not truly the sum of all weights
			if (selection < 0) continue;
			// TODO: I doubt additional calculations are done when the selected item is air, but check
			if (lootTable->pools[p].lootItems[i].type == Item_None) continue;
			if (lootTable->pools[p].lootItems[i].rarity > 1) {
				if (generalizedNextInt(&rng, lootTable->pools[p].lootItems[i].rarity)) continue;
			}
			output[outputSize].type = lootTable->pools[p].lootItems[i].type;
			output[outputSize].count = lootTable->pools[p].lootItems[i].minCount;
			if (lootTable->pools[p].lootItems[i].minCount < lootTable->pools[p].lootItems[i].maxCount) output[outputSize].count += generalizedNextInt(&rng, lootTable->pools[p].lootItems[i].maxCount - lootTable->pools[p].lootItems[i].minCount + 1);
			if (lootTable->pools[p].lootItems[i].setAttributes) lootTable->pools[p].lootItems[i].setAttributes(&output[outputSize], &rng);
			output[outputSize].chestIndex = generalizedNextInt(&rng, MAX_CHEST_CAPACITY);
			++outputSize;
			if (outputSize >= (ssize_t)outputCapacity) return outputCapacity;
		}
	}
	return outputSize;
}