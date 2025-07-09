#include "entry.h"

size_t getEntryCount_BonusChest(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_3_1) return 0;
			return 9;
		default: return 0;
	}
}

size_t getEntryCount_DesertPyramid(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_3_1) return 0;
			if (version < Version_1_4_6) return 6;
			if (version < Version_1_6_1) return 7;
			return 11;
		default: return 0;
	}
}

size_t getEntryCount_Fortress(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_6_1) return 0;
			return 11;
		default: return 0;
	}
}

size_t getEntryCount_JungleTempleTrap(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_3_1) return 0;
			return 1;
		default: return 0;
	}
}

size_t getEntryCount_JungleTempleTreasure(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_3_1) return 0;
			if (version < Version_1_4_6) return 6;
			if (version < Version_1_6_1) return 7;
			return 11;
		default: return 0;
	}
}

size_t getEntryCount_Mineshaft(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			if (version < Version_1_0) return 10;
			if (version < Version_1_4_6) return 11;
			if (version < Version_1_6_1) return 12;
			return 14;
		default: return 0;
	}
}

size_t getEntryCount_MonsterRoom(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Infdev_20100625_1917) return 0;
			if (version < Version_Alpha_1_0_1_01) return 8;
			if (version < Version_Alpha_1_0_14) return 9;
			if (version < Version_Beta_1_4) return 10;
			if (version < Version_1_4_6) return 11;
			if (version < Version_1_6_1) return 12;
			return 16;
		default: return 0;
	}
}

size_t getEntryCount_StrongholdChestCorridor(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_0) return 0;
			if (version < Version_1_4_6) return 14;
			if (version < Version_1_6_1) return 15;
			return 19;
		default: return 0;
	}
}

size_t getEntryCount_StrongholdLibrary(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			if (version < Version_1_4_6) return 4;
			return 5;
		default: return 0;
	}
}

size_t getEntryCount_StrongholdRoomCrossing(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			if (version < Version_1_4_6) return 7;
			return 8;
		default: return 0;
	}
}

size_t getEntryCount_Village(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_1) return 0;
			if (version < Version_1_6_1) return 13;
			return 17;
		default: return 0;
	}
}

size_t getEntryCount(size_t poolNumber, enum Source source, enum Version version, enum Biome biome) {
	switch (source) {
		case Source_Bonus_Chest: return getEntryCount_BonusChest(poolNumber, version, biome);
		case Source_Desert_Pyramid: return getEntryCount_DesertPyramid(poolNumber, version, biome);
		case Source_Fortress: return getEntryCount_Fortress(poolNumber, version, biome);
		case Source_Jungle_Temple_Trap: return getEntryCount_JungleTempleTrap(poolNumber, version, biome);
		case Source_Jungle_Temple_Treasure: return getEntryCount_JungleTempleTreasure(poolNumber, version, biome);
		case Source_Mineshaft: return getEntryCount_Mineshaft(poolNumber, version, biome);
		case Source_Monster_Room: return getEntryCount_MonsterRoom(poolNumber, version, biome);
		case Source_Stronghold_Chest_Corridor: return getEntryCount_StrongholdChestCorridor(poolNumber, version, biome);
		case Source_Stronghold_Library: return getEntryCount_StrongholdLibrary(poolNumber, version, biome);
		case Source_Stronghold_Room_Crossing: return getEntryCount_StrongholdRoomCrossing(poolNumber, version, biome);
		case Source_Village: return getEntryCount_Village(poolNumber, version, biome);
		default: return 0;
	}
}


int getMaxStackCount(enum ItemType item, enum Version version) {
	// WARNING: A lot of this has not been verified, and is admittedly taking the Minecraft Wiki at its word.
	switch (item) {
		// 0.24_SURVIVAL_TEST or earlier (when the inventory was added)
		case Item_Oak_Log:
		case Item_Oak_Planks:
		case Item_Sapling:
			if (version < Version_0_24_SURVIVAL_TEST_03) return 0; // 0.24_SURVIVAL_TEST is lost
			return 64;
		case Item_Arrow:
			if (version < Version_0_24_SURVIVAL_TEST_03) return 0; // 0.24_SURVIVAL_TEST is lost
			if (version < Version_0_31_20100124_2310) return INT_MAX; // Unverified (counter was used). 0.31 20100122-2251 is lost
			return 64;
		// 0.31 20091231-2147
		case Item_Iron_Sword:
			if (version < Version_0_31_20091231_2255) return 0; // 0.31 20091231-2147 is lost
			return 1;
		// 0.31 20091231-2255
		case Item_Iron_Boots:
		case Item_Iron_Chestplate:
		case Item_Iron_Helmet:
		case Item_Iron_Leggings:
			if (version < Version_0_31_20091231_2255) return 0;
			return 1;
		case Item_Apple:
			if (version < Version_0_31_20091231_2255) return 0;
			if (version < Version_Beta_1_8) return 1;
			return 64;
		// 0.31 20100110
		case Item_Flint_and_Steel:
		case Item_Iron_Pickaxe:
			if (version < Version_0_31_20100110) return 0;
			return 1;
		// 0.31 20100128-2200
		case Item_Stone_Axe:
		case Item_Stone_Pickaxe:
		case Item_Wooden_Axe:
		case Item_Wooden_Pickaxe:
			if (version < Version_0_31_20100128_2304) return 0; // 0.31 20100128-2200 is lost
			return 1;
		case Item_Coal:
		case Item_Diamond:
		case Item_Gold_Ingot:
		case Item_Iron_Ingot:
			if (version < Version_0_31_20100128_2304) return 0; // 0.31 20100128-2200 is lost
			return 64;
		// 0.31 20100129-1447
		case Item_Stick:
			if (version < Version_0_31_20100129_1452) return 0; // 0.31 20100129-1447 is lost
			return 64;
		// 0.31 20100129-2332
		case Item_Golden_Sword:
			if (version < Version_0_31_20100130) return 0; // 0.31 20100129-2332 is lost
			return 1;
		// 0.31 20100130
		case Item_Gunpowder:
		case Item_String:
			if (version < Version_0_31_20100130) return 0;
			return 64;
		// Indev 20100206-2034
		case Item_Golden_Chestplate:
			if (version < Version_Indev_20100206_2103) return 0; // Indev 20100206-2034 is lost
			return 1;
		case Item_Wheat:
			if (version < Version_Indev_20100206_2103) return 0; // Indev 20100206-2034 is lost
			return 64;
		case Item_Bread:
			if (version < Version_Indev_20100206_2103) return 0; // Indev 20100206-2034 is lost
			if (version < Version_Beta_1_8) return 1;
			return 64;
		// Infdev 20100615
		case Item_Bucket:
			if (version < Version_Infdev_20100615) return 0;
			if (version < Version_1_3_1) return 1;
			return 16;
		// Infdev 20100618
		case Item_Obsidian:
		case Item_Rail:
			if (version < Version_Infdev_20100618) return 0;
			return 64;
		// Infdev 20100625-1917
		case Item_Saddle:
			if (version < Version_Infdev_20100625_1917) return 0;
			return 1;
		case Item_Golden_Apple:
			if (version < Version_Infdev_20100625_1917) return 0;
			if (version < Version_Beta_1_8) return 1;
			return 64;
		// Alpha 1.0.1
		case Item_Redstone:
			if (version < Version_Alpha_1_0_1_01) return 0; // Alpha 1.0.1 is lost
			return 64;
		// Alpha 1.0.11
		case Item_Book:
		case Item_Paper:
			if (version < Version_Alpha_1_0_11) return 0;
			return 64;
		// Alpha 1.0.14
		case Item_Music_Disc:
			if (version < Version_Alpha_1_0_14) return 0;
			return 1;
		// Alpha 1.1.0
		case Item_Compass:
			if (version < Version_Alpha_1_1_0) return 0;
			return 64;
		// Beta 1.2
		case Item_Bone:
		case Item_Cocoa_Beans:
		case Item_Lapis_Lazuli:
			if (version < Version_Beta_1_2) return 0;
			return 64;
		// Beta 1.6
		case Item_Map:
			if (version < Version_Beta_1_6) return 0;
			return 64;
		// Beta 1.8
		case Item_Melon_Seeds:
		case Item_Pumpkin_Seeds:
		case Item_Rotten_Flesh:
			if (version < Version_Beta_1_8) return 0;
			return 64;
		case Item_Ender_Pearl:
			if (version < Version_Beta_1_8) return 0;
			if (version < Version_1_0) return 64;
			return 16;
		// 1.0
		case Item_Nether_Wart:
			if (version < Version_1_0) return 0;
			return 64;
		// 1.3.1
		case Item_Emerald:
			if (version < Version_1_3_1) return 0;
			return 64;
		// 1.4.6
		case Item_Enchanted_Book:
			if (version < Version_1_4_6) return 0;
			return 1;
		// 1.6.1
		case Item_Diamond_Horse_Armor:
		case Item_Golden_Horse_Armor:
		case Item_Iron_Horse_Armor:
			if (version < Version_1_6_1) return 0;
			return 1;
		case Item_Name_Tag:
			if (version < Version_1_6_1) return 0;
			return 64;
		default: return 0;
	}
}