#include "tableValues.h"

bool addLootToTable_MonsterRoom(enum Version version, enum Biome biome, LootTable *const lootTable) {
	(void)biome;
	if (version < Infdev_20100625_1917) return false;
	lootTable->prngType = PRNG_java_util_Random;
		// Pool 0
		lootTable->pools[0].minRolls = 8, lootTable->pools[0].maxRolls = 8;
		lootTable->pools[0].summedWeight = 10;
			// Item 1
			lootTable->pools[0].lootItems[0].type = Item_Saddle;
			lootTable->pools[0].lootItems[0].minCount = 1, lootTable->pools[0].lootItems[0].maxCount = 1;
			lootTable->pools[0].lootItems[0].weight = 1, lootTable->pools[0].lootItems[0].rarity = 1;
			lootTable->pools[0].lootItems[0].setAttributes = lootAttributes_none;
			// Item 2
			lootTable->pools[0].lootItems[1].type = Item_Iron_Ingot;
			lootTable->pools[0].lootItems[1].minCount = 1, lootTable->pools[0].lootItems[1].maxCount = 4;
			lootTable->pools[0].lootItems[1].weight = 1, lootTable->pools[0].lootItems[1].rarity = 1;
			lootTable->pools[0].lootItems[1].setAttributes = lootAttributes_none;
			// Item 3
			lootTable->pools[0].lootItems[2].type = Item_Bread;
			lootTable->pools[0].lootItems[2].minCount = 1, lootTable->pools[0].lootItems[2].maxCount = 1;
			lootTable->pools[0].lootItems[2].weight = 1, lootTable->pools[0].lootItems[2].rarity = 1;
			lootTable->pools[0].lootItems[2].setAttributes = lootAttributes_none;
			// Item 4
			lootTable->pools[0].lootItems[3].type = Item_Wheat;
			lootTable->pools[0].lootItems[3].minCount = 1, lootTable->pools[0].lootItems[3].maxCount = 4;
			lootTable->pools[0].lootItems[3].weight = 1, lootTable->pools[0].lootItems[3].rarity = 1;
			lootTable->pools[0].lootItems[3].setAttributes = lootAttributes_none;
			// Item 5
			lootTable->pools[0].lootItems[4].type = Item_Gunpowder;
			lootTable->pools[0].lootItems[4].minCount = 1, lootTable->pools[0].lootItems[4].maxCount = 4;
			lootTable->pools[0].lootItems[4].weight = 1, lootTable->pools[0].lootItems[4].rarity = 1;
			lootTable->pools[0].lootItems[4].setAttributes = lootAttributes_none;
			// Item 6
			lootTable->pools[0].lootItems[5].type = Item_String;
			lootTable->pools[0].lootItems[5].minCount = 1, lootTable->pools[0].lootItems[5].maxCount = 4;
			lootTable->pools[0].lootItems[5].weight = 1, lootTable->pools[0].lootItems[5].rarity = 1;
			lootTable->pools[0].lootItems[5].setAttributes = lootAttributes_none;
			// Item 7
			lootTable->pools[0].lootItems[6].type = Item_Bucket;
			lootTable->pools[0].lootItems[6].minCount = 1, lootTable->pools[0].lootItems[6].maxCount = 1;
			lootTable->pools[0].lootItems[6].weight = 1, lootTable->pools[0].lootItems[6].rarity = 1;
			lootTable->pools[0].lootItems[6].setAttributes = lootAttributes_none;
			// Item 8
			lootTable->pools[0].lootItems[7].type = Item_Golden_Apple;
			lootTable->pools[0].lootItems[7].minCount = 1, lootTable->pools[0].lootItems[7].maxCount = 1;
			lootTable->pools[0].lootItems[7].weight = 1, lootTable->pools[0].lootItems[7].rarity = 100;
			lootTable->pools[0].lootItems[7].setAttributes = lootAttributes_none;
	if (version < Alpha_1_0_1_01) return true;
		// Total weight increased
		lootTable->pools[0].summedWeight = 11;
			// Item 9
			lootTable->pools[0].lootItems[8].type = Item_Redstone;
			lootTable->pools[0].lootItems[8].minCount = 1, lootTable->pools[0].lootItems[8].maxCount = 4;
			lootTable->pools[0].lootItems[8].weight = 1, lootTable->pools[0].lootItems[8].rarity = 2;
			lootTable->pools[0].lootItems[8].setAttributes = lootAttributes_none;
	if (version < Alpha_1_0_14) return true;
			// Item 10
			lootTable->pools[0].lootItems[9].type = Item_Music_Disc;
			lootTable->pools[0].lootItems[9].minCount = 1, lootTable->pools[0].lootItems[9].maxCount = 1;
			lootTable->pools[0].lootItems[9].weight = 1, lootTable->pools[0].lootItems[9].rarity = 2;
			lootTable->pools[0].lootItems[9].setAttributes = lootAttributes_discType;
	if (version < Beta_1_4) return true;
			// Item 11
			lootTable->pools[0].lootItems[10].type = Item_Cocoa_Beans;
			lootTable->pools[0].lootItems[10].minCount = 1, lootTable->pools[0].lootItems[10].maxCount = 1;
			lootTable->pools[0].lootItems[10].weight = 1, lootTable->pools[0].lootItems[10].rarity = 1;
			lootTable->pools[0].lootItems[10].setAttributes = lootAttributes_none;
	return true;
}

bool addLootToTable(enum Structure structure, enum Version version, enum Biome biome, LootTable *const lootTable) {
	switch (structure) {
		case Structure_Monster_Room: return addLootToTable_MonsterRoom(version, biome, lootTable);
		default: return false;
	}
}