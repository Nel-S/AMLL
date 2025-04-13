#include "table.h"

enum TableFlags {
	Sum_of_Entries_Weights = -1
};

bool addLootToTable_BonusChest(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 10, lootTable->pools[0].maxRolls = 10;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-8
			lootTable->pools[0].entries[0] = (LootEntry){Item_Stick, 1, 3, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Planks, 1, 3, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Log, 1, 3, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Stone_Axe, 1, 1, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Wooden_Axe, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Stone_Pickaxe, 1, 1, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[6] = (LootEntry){Item_Wooden_Pickaxe, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[7] = (LootEntry){Item_Apple, 2, 3, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[8] = (LootEntry){Item_Stick, 2, 3, 3, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_DesertPyramid(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-5
			lootTable->pools[0].entries[0] = (LootEntry){Item_Diamond, 1, 3, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Iron_Ingot, 1, 5, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Gold_Ingot, 2, 7, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Emerald, 1, 3, 2, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Bone, 4, 6, 20, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Rotten_Flesh, 3, 7, 16, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_JungleTempleTrap(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_DISPENSER_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 2;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entry 0
			lootTable->pools[0].entries[0] = (LootEntry){Item_Arrow, 2, 7, 30, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_JungleTempleTreasure(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-5
			lootTable->pools[0].entries[0] = (LootEntry){Item_Diamond, 1, 3, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Iron_Ingot, 1, 5, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Gold_Ingot, 2, 7, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Emerald, 1, 3, 2, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Bone, 4, 6, 20, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Rotten_Flesh, 3, 7, 16, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_Mineshaft(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 3, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-9
			lootTable->pools[0].entries[0] = (LootEntry){Item_Iron_Ingot, 1, 5, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Gold_Ingot, 1, 3, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Redstone, 4, 9, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Lapis_Lazuli, 4, 9, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Diamond, 1, 2, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Coal, 3, 8, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[6] = (LootEntry){Item_Bread, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[7] = (LootEntry){Item_Iron_Pickaxe, 1, 1, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[8] = (LootEntry){Item_Rail, 4, 8, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[9] = (LootEntry){Item_Melon_Seeds, 2, 4, 10, 1, lootAttributes_none};
	if (version < Version_1_0) return true;
		lootTable->pools[0].summedWeight = 75;
			// Entry 10
			lootTable->pools[0].entries[10] = (LootEntry){Item_Pumpkin_Seeds, 2, 4, 10, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_MonsterRoom(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Infdev_20100625_1917) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 8, lootTable->pools[0].maxRolls = 8;
		lootTable->pools[0].summedWeight = 10;
			// Entries 0-7
			lootTable->pools[0].entries[0] = (LootEntry){Item_Saddle, 1, 1, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Iron_Ingot, 1, 4, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Bread, 1, 1, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Wheat, 1, 4, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Gunpowder, 1, 4, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_String, 1, 4, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[6] = (LootEntry){Item_Bucket, 1, 1, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[7] = (LootEntry){Item_Golden_Apple, 1, 1, 1, 100, lootAttributes_none};
	if (version < Version_Alpha_1_0_1_01) return true;
		// Total weight increased
		lootTable->pools[0].summedWeight = 11;
			// Entry 8
			lootTable->pools[0].entries[8] = (LootEntry){Item_Redstone, 1, 4, 1, 2, lootAttributes_none};
	if (version < Version_Alpha_1_0_14) return true;
			// Entry 9
			lootTable->pools[0].entries[9] = (LootEntry){Item_Music_Disc, 1, 1, 1, 10, lootAttributes_discType};
	if (version < Version_Beta_1_4) return true;
			// Entry 10
			lootTable->pools[0].entries[10] = (LootEntry){Item_Cocoa_Beans, 1, 1, 1, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_StrongholdChestCorridor(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_0) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 3;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-13
			lootTable->pools[0].entries[0] = (LootEntry){Item_Ender_Pearl, 1, 1, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Diamond, 1, 3, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Iron_Ingot, 1, 5, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Gold_Ingot, 1, 3, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Redstone, 4, 9, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Bread, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[6] = (LootEntry){Item_Apple, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[7] = (LootEntry){Item_Iron_Pickaxe, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[8] = (LootEntry){Item_Iron_Sword, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[9] = (LootEntry){Item_Iron_Chestplate, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[10] = (LootEntry){Item_Iron_Helmet, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[11] = (LootEntry){Item_Iron_Leggings, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[12] = (LootEntry){Item_Iron_Boots, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[13] = (LootEntry){Item_Golden_Apple, 1, 1, 1, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_StrongholdLibrary(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 4;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-3
			lootTable->pools[0].entries[0] = (LootEntry){Item_Book, 1, 3, 20, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Paper, 2, 7, 20, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Filled_Map, 1, 1, 1, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Compass, 1, 1, 1, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_StrongholdRoomCrossing(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 4;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-6
			lootTable->pools[0].entries[0] = (LootEntry){Item_Iron_Ingot, 1, 5, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Gold_Ingot, 1, 3, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Redstone, 4, 9, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Coal, 3, 8, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Bread, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Apple, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[6] = (LootEntry){Item_Iron_Pickaxe, 1, 1, 1, 1, lootAttributes_none};
	return true;
}

bool addLootToTable_Village(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 3, lootTable->pools[0].maxRolls = 8;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-12
			lootTable->pools[0].entries[0] = (LootEntry){Item_Diamond, 1, 3, 3, 1, lootAttributes_none};
			lootTable->pools[0].entries[1] = (LootEntry){Item_Iron_Ingot, 1, 5, 10, 1, lootAttributes_none};
			lootTable->pools[0].entries[2] = (LootEntry){Item_Gold_Ingot, 1, 3, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[3] = (LootEntry){Item_Bread, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[4] = (LootEntry){Item_Apple, 1, 3, 15, 1, lootAttributes_none};
			lootTable->pools[0].entries[5] = (LootEntry){Item_Iron_Pickaxe, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[6] = (LootEntry){Item_Iron_Sword, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[7] = (LootEntry){Item_Iron_Chestplate, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[8] = (LootEntry){Item_Iron_Helmet, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[9] = (LootEntry){Item_Iron_Leggings, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[10] = (LootEntry){Item_Iron_Boots, 1, 1, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[11] = (LootEntry){Item_Obsidian, 3, 7, 5, 1, lootAttributes_none};
			lootTable->pools[0].entries[12] = (LootEntry){Item_Sapling, 3, 7, 5, 1, lootAttributes_none};
	return true;
}

bool addLootToTable(LootTable *const lootTable, enum Source source, enum Version version, enum Biome biome) {
	if (!lootTable) return false;
	switch (source) {
		case Source_Bonus_Chest: if (!addLootToTable_BonusChest(lootTable, version, biome)) return false;
			break;
		case Source_Desert_Pyramid: if (!addLootToTable_DesertPyramid(lootTable, version, biome)) return false;
			break;
		case Source_Jungle_Temple_Trap: if (!addLootToTable_JungleTempleTrap(lootTable, version, biome)) return false;
			break;
		case Source_Jungle_Temple_Treasure: if (!addLootToTable_JungleTempleTreasure(lootTable, version, biome)) return false;
			break;
		case Source_Mineshaft: if (!addLootToTable_Mineshaft(lootTable, version, biome)) return false;
			break;
		case Source_Monster_Room: if (!addLootToTable_MonsterRoom(lootTable, version, biome)) return false;
			break;
		case Source_Stronghold_Chest_Corridor: if (!addLootToTable_StrongholdChestCorridor(lootTable, version, biome)) return false;
			break;
		case Source_Stronghold_Library: if (!addLootToTable_StrongholdLibrary(lootTable, version, biome)) return false;
			break;
		case Source_Stronghold_Room_Crossing: if (!addLootToTable_StrongholdRoomCrossing(lootTable, version, biome)) return false;
			break;
		case Source_Village: if (!addLootToTable_Village(lootTable, version, biome)) return false;
			break;
		default: return false;
	}
	// If summed weight was flagged as being the sum of entries' weights, calculate summed weight 
	for (size_t p = 0; p < lootTable->poolCount; ++p) {
		if (lootTable->pools[p].summedWeight != Sum_of_Entries_Weights) continue;
		lootTable->pools[p].summedWeight = 0;
		for (size_t e = 0; e < lootTable->pools[p].entryCount; ++e) lootTable->pools[p].summedWeight += lootTable->pools[p].entries[e].weight;
	}
	return true;
}