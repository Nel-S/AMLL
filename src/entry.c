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
			return 6;
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
			return 6;
		default: return 0;
	}
}

size_t getEntryCount_Mineshaft(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			if (version < Version_1_0) return 10;
			return 11;
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
			return 11;
		default: return 0;
	}
}

size_t getEntryCount_StrongholdChestCorridor(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_0) return 0;
			return 14;
		default: return 0;
	}
}

size_t getEntryCount_StrongholdLibrary(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			return 4;
		default: return 0;
	}
}

size_t getEntryCount_StrongholdRoomCrossing(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			return 7;
		default: return 0;
	}
}

size_t getEntryCount_Village(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_1_1) return 0;
			return 13;
		default: return 0;
	}
}

size_t getEntryCount(size_t poolNumber, enum Source source, enum Version version, enum Biome biome) {
	switch (source) {
		case Source_Bonus_Chest: return getEntryCount_BonusChest(poolNumber, version, biome);
		case Source_Desert_Pyramid: return getEntryCount_DesertPyramid(poolNumber, version, biome);
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