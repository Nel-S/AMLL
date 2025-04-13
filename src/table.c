#include "table.h"

bool addLootToTable_Mineshaft(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
		// Pool 0
		lootTable->pools[0].minRolls = 3, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = 65;
			// Item 0
			lootTable->pools[0].entries[0].type = Item_Iron_Ingot;
			lootTable->pools[0].entries[0].minCount = 1, lootTable->pools[0].entries[0].maxCount = 5;
			lootTable->pools[0].entries[0].weight = 10, lootTable->pools[0].entries[0].rarity = 1;
			lootTable->pools[0].entries[0].setAttributes = lootAttributes_none;
			// Item 1
			lootTable->pools[0].entries[1].type = Item_Gold_Ingot;
			lootTable->pools[0].entries[1].minCount = 1, lootTable->pools[0].entries[1].maxCount = 3;
			lootTable->pools[0].entries[1].weight = 5, lootTable->pools[0].entries[1].rarity = 1;
			lootTable->pools[0].entries[1].setAttributes = lootAttributes_none;
			// Item 2
			lootTable->pools[0].entries[2].type = Item_Redstone;
			lootTable->pools[0].entries[2].minCount = 4, lootTable->pools[0].entries[2].maxCount = 9;
			lootTable->pools[0].entries[2].weight = 5, lootTable->pools[0].entries[2].rarity = 1;
			lootTable->pools[0].entries[2].setAttributes = lootAttributes_none;
			// Item 3
			lootTable->pools[0].entries[3].type = Item_Lapis_Lazuli;
			lootTable->pools[0].entries[3].minCount = 4, lootTable->pools[0].entries[3].maxCount = 9;
			lootTable->pools[0].entries[3].weight = 5, lootTable->pools[0].entries[3].rarity = 1;
			lootTable->pools[0].entries[3].setAttributes = lootAttributes_none;
			// Item 4
			lootTable->pools[0].entries[4].type = Item_Diamond;
			lootTable->pools[0].entries[4].minCount = 1, lootTable->pools[0].entries[4].maxCount = 2;
			lootTable->pools[0].entries[4].weight = 3, lootTable->pools[0].entries[4].rarity = 1;
			lootTable->pools[0].entries[4].setAttributes = lootAttributes_none;
			// Item 5
			lootTable->pools[0].entries[5].type = Item_Coal;
			lootTable->pools[0].entries[5].minCount = 3, lootTable->pools[0].entries[5].maxCount = 8;
			lootTable->pools[0].entries[5].weight = 10, lootTable->pools[0].entries[5].rarity = 1;
			lootTable->pools[0].entries[5].setAttributes = lootAttributes_none;
			// Item 6
			lootTable->pools[0].entries[6].type = Item_Bread;
			lootTable->pools[0].entries[6].minCount = 1, lootTable->pools[0].entries[6].maxCount = 3;
			lootTable->pools[0].entries[6].weight = 15, lootTable->pools[0].entries[6].rarity = 1;
			lootTable->pools[0].entries[6].setAttributes = lootAttributes_none;
			// Item 7
			lootTable->pools[0].entries[7].type = Item_Iron_Pickaxe;
			lootTable->pools[0].entries[7].minCount = 1, lootTable->pools[0].entries[7].maxCount = 1;
			lootTable->pools[0].entries[7].weight = 1, lootTable->pools[0].entries[7].rarity = 1;
			lootTable->pools[0].entries[7].setAttributes = lootAttributes_none;
			// Item 8
			lootTable->pools[0].entries[8].type = Item_Rail;
			lootTable->pools[0].entries[8].minCount = 4, lootTable->pools[0].entries[8].maxCount = 8;
			lootTable->pools[0].entries[8].weight = 1, lootTable->pools[0].entries[8].rarity = 1;
			lootTable->pools[0].entries[8].setAttributes = lootAttributes_none;
			// Item 9
			lootTable->pools[0].entries[9].type = Item_Melon_Seeds;
			lootTable->pools[0].entries[9].minCount = 2, lootTable->pools[0].entries[9].maxCount = 4;
			lootTable->pools[0].entries[9].weight = 10, lootTable->pools[0].entries[9].rarity = 1;
			lootTable->pools[0].entries[9].setAttributes = lootAttributes_none;
	return true;
}

bool addLootToTable_MonsterRoom(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Infdev_20100625_1917) return false;
	lootTable->prngType = PRNG_java_util_Random;
		// Pool 0
		lootTable->pools[0].minRolls = 8, lootTable->pools[0].maxRolls = 8;
		lootTable->pools[0].summedWeight = 10;
			// Item 0
			lootTable->pools[0].entries[0].type = Item_Saddle;
			lootTable->pools[0].entries[0].minCount = 1, lootTable->pools[0].entries[0].maxCount = 1;
			lootTable->pools[0].entries[0].weight = 1, lootTable->pools[0].entries[0].rarity = 1;
			lootTable->pools[0].entries[0].setAttributes = lootAttributes_none;
			// Item 1
			lootTable->pools[0].entries[1].type = Item_Iron_Ingot;
			lootTable->pools[0].entries[1].minCount = 1, lootTable->pools[0].entries[1].maxCount = 4;
			lootTable->pools[0].entries[1].weight = 1, lootTable->pools[0].entries[1].rarity = 1;
			lootTable->pools[0].entries[1].setAttributes = lootAttributes_none;
			// Item 2
			lootTable->pools[0].entries[2].type = Item_Bread;
			lootTable->pools[0].entries[2].minCount = 1, lootTable->pools[0].entries[2].maxCount = 1;
			lootTable->pools[0].entries[2].weight = 1, lootTable->pools[0].entries[2].rarity = 1;
			lootTable->pools[0].entries[2].setAttributes = lootAttributes_none;
			// Item 3
			lootTable->pools[0].entries[3].type = Item_Wheat;
			lootTable->pools[0].entries[3].minCount = 1, lootTable->pools[0].entries[3].maxCount = 4;
			lootTable->pools[0].entries[3].weight = 1, lootTable->pools[0].entries[3].rarity = 1;
			lootTable->pools[0].entries[3].setAttributes = lootAttributes_none;
			// Item 4
			lootTable->pools[0].entries[4].type = Item_Gunpowder;
			lootTable->pools[0].entries[4].minCount = 1, lootTable->pools[0].entries[4].maxCount = 4;
			lootTable->pools[0].entries[4].weight = 1, lootTable->pools[0].entries[4].rarity = 1;
			lootTable->pools[0].entries[4].setAttributes = lootAttributes_none;
			// Item 5
			lootTable->pools[0].entries[5].type = Item_String;
			lootTable->pools[0].entries[5].minCount = 1, lootTable->pools[0].entries[5].maxCount = 4;
			lootTable->pools[0].entries[5].weight = 1, lootTable->pools[0].entries[5].rarity = 1;
			lootTable->pools[0].entries[5].setAttributes = lootAttributes_none;
			// Item 6
			lootTable->pools[0].entries[6].type = Item_Bucket;
			lootTable->pools[0].entries[6].minCount = 1, lootTable->pools[0].entries[6].maxCount = 1;
			lootTable->pools[0].entries[6].weight = 1, lootTable->pools[0].entries[6].rarity = 1;
			lootTable->pools[0].entries[6].setAttributes = lootAttributes_none;
			// Item 7
			lootTable->pools[0].entries[7].type = Item_Golden_Apple;
			lootTable->pools[0].entries[7].minCount = 1, lootTable->pools[0].entries[7].maxCount = 1;
			lootTable->pools[0].entries[7].weight = 1, lootTable->pools[0].entries[7].rarity = 100;
			lootTable->pools[0].entries[7].setAttributes = lootAttributes_none;
	if (version < Version_Alpha_1_0_1_01) return true;
		// Total weight increased
		lootTable->pools[0].summedWeight = 11;
			// Item 8
			lootTable->pools[0].entries[8].type = Item_Redstone;
			lootTable->pools[0].entries[8].minCount = 1, lootTable->pools[0].entries[8].maxCount = 4;
			lootTable->pools[0].entries[8].weight = 1, lootTable->pools[0].entries[8].rarity = 2;
			lootTable->pools[0].entries[8].setAttributes = lootAttributes_none;
	if (version < Version_Alpha_1_0_14) return true;
			// Item 9
			lootTable->pools[0].entries[9].type = Item_Music_Disc;
			lootTable->pools[0].entries[9].minCount = 1, lootTable->pools[0].entries[9].maxCount = 1;
			lootTable->pools[0].entries[9].weight = 1, lootTable->pools[0].entries[9].rarity = 10;
			lootTable->pools[0].entries[9].setAttributes = lootAttributes_discType;
	if (version < Version_Beta_1_4) return true;
			// Item 10
			lootTable->pools[0].entries[10].type = Item_Cocoa_Beans;
			lootTable->pools[0].entries[10].minCount = 1, lootTable->pools[0].entries[10].maxCount = 1;
			lootTable->pools[0].entries[10].weight = 1, lootTable->pools[0].entries[10].rarity = 1;
			lootTable->pools[0].entries[10].setAttributes = lootAttributes_none;
	return true;
}

bool addLootToTable_StrongholdLibrary(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
		// Pool 0
		lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 4;
		lootTable->pools[0].summedWeight = 42;
			// Item 0
			lootTable->pools[0].entries[0].type = Item_Book;
			lootTable->pools[0].entries[0].minCount = 1, lootTable->pools[0].entries[0].maxCount = 3;
			lootTable->pools[0].entries[0].weight = 20, lootTable->pools[0].entries[0].rarity = 1;
			lootTable->pools[0].entries[0].setAttributes = lootAttributes_none;
			// Item 1
			lootTable->pools[0].entries[1].type = Item_Paper;
			lootTable->pools[0].entries[1].minCount = 2, lootTable->pools[0].entries[1].maxCount = 7;
			lootTable->pools[0].entries[1].weight = 20, lootTable->pools[0].entries[1].rarity = 1;
			lootTable->pools[0].entries[1].setAttributes = lootAttributes_none;
			// Item 2
			lootTable->pools[0].entries[2].type = Item_Filled_Map;
			lootTable->pools[0].entries[2].minCount = 1, lootTable->pools[0].entries[2].maxCount = 1;
			lootTable->pools[0].entries[2].weight = 1, lootTable->pools[0].entries[2].rarity = 1;
			lootTable->pools[0].entries[2].setAttributes = lootAttributes_none;
			// Item 3
			lootTable->pools[0].entries[3].type = Item_Compass;
			lootTable->pools[0].entries[3].minCount = 1, lootTable->pools[0].entries[3].maxCount = 1;
			lootTable->pools[0].entries[3].weight = 1, lootTable->pools[0].entries[3].rarity = 1;
			lootTable->pools[0].entries[3].setAttributes = lootAttributes_none;
	return true;
}

bool addLootToTable_StrongholdRoomCrossing(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
		// Pool 0
		lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 4;
		lootTable->pools[0].summedWeight = 61;
			// Item 0
			lootTable->pools[0].entries[0].type = Item_Iron_Ingot;
			lootTable->pools[0].entries[0].minCount = 1, lootTable->pools[0].entries[0].maxCount = 5;
			lootTable->pools[0].entries[0].weight = 10, lootTable->pools[0].entries[0].rarity = 1;
			lootTable->pools[0].entries[0].setAttributes = lootAttributes_none;
			// Item 1
			lootTable->pools[0].entries[1].type = Item_Gold_Ingot;
			lootTable->pools[0].entries[1].minCount = 1, lootTable->pools[0].entries[1].maxCount = 3;
			lootTable->pools[0].entries[1].weight = 5, lootTable->pools[0].entries[1].rarity = 1;
			lootTable->pools[0].entries[1].setAttributes = lootAttributes_none;
			// Item 2
			lootTable->pools[0].entries[2].type = Item_Redstone;
			lootTable->pools[0].entries[2].minCount = 4, lootTable->pools[0].entries[2].maxCount = 9;
			lootTable->pools[0].entries[2].weight = 5, lootTable->pools[0].entries[2].rarity = 1;
			lootTable->pools[0].entries[2].setAttributes = lootAttributes_none;
			// Item 3
			lootTable->pools[0].entries[3].type = Item_Coal;
			lootTable->pools[0].entries[3].minCount = 3, lootTable->pools[0].entries[3].maxCount = 8;
			lootTable->pools[0].entries[3].weight = 10, lootTable->pools[0].entries[3].rarity = 1;
			lootTable->pools[0].entries[3].setAttributes = lootAttributes_none;
			// Item 4
			lootTable->pools[0].entries[4].type = Item_Bread;
			lootTable->pools[0].entries[4].minCount = 1, lootTable->pools[0].entries[4].maxCount = 3;
			lootTable->pools[0].entries[4].weight = 15, lootTable->pools[0].entries[4].rarity = 1;
			lootTable->pools[0].entries[4].setAttributes = lootAttributes_none;
			// Item 5
			lootTable->pools[0].entries[5].type = Item_Apple;
			lootTable->pools[0].entries[5].minCount = 1, lootTable->pools[0].entries[5].maxCount = 3;
			lootTable->pools[0].entries[5].weight = 15, lootTable->pools[0].entries[5].rarity = 1;
			lootTable->pools[0].entries[5].setAttributes = lootAttributes_none;
			// Item 6
			lootTable->pools[0].entries[6].type = Item_Iron_Pickaxe;
			lootTable->pools[0].entries[6].minCount = 1, lootTable->pools[0].entries[6].maxCount = 1;
			lootTable->pools[0].entries[6].weight = 1, lootTable->pools[0].entries[6].rarity = 1;
			lootTable->pools[0].entries[6].setAttributes = lootAttributes_none;
	return true;
}

bool addLootToTable(LootTable *const lootTable, enum Structure structure, enum Version version, enum Biome biome) {
	switch (structure) {
		case Structure_Mineshaft: return addLootToTable_Mineshaft(lootTable, version, biome);
		case Structure_Monster_Room: return addLootToTable_MonsterRoom(lootTable, version, biome);
		case Structure_Stronghold_Library: return addLootToTable_StrongholdLibrary(lootTable, version, biome);
		case Structure_Stronghold_Room_Crossing: return addLootToTable_StrongholdRoomCrossing(lootTable, version, biome);
		default: return false;
	}
}