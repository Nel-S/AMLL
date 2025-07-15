#include "pool.h"

size_t getPoolCount_BonusChest(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_3_1) return 0;
	return 1;
}

size_t getPoolCount_DesertPyramid(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_3_1) return 0;
	return 1;
}

size_t getPoolCount_Fortress(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_6_1) return 0;
	return 1;
}

size_t getPoolCount_JungleTempleTrap(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_3_1) return 0;
	return 1;
}

size_t getPoolCount_JungleTempleTreasure(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_3_1) return 0;
	return 1;
}

size_t getPoolCount_Mineshaft(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Beta_1_8) return 0;
	return 1;
}

size_t getPoolCount_MonsterRoom(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Infdev_20100625_1917) return 0;
	return 1;
}

size_t getPoolCount_StrongholdChestCorridor(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_0) return 0;
	return 1;
}

size_t getPoolCount_StrongholdLibrary(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Beta_1_8) return 0;
	return 1;
}

size_t getPoolCount_StrongholdRoomCrossing(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Beta_1_8) return 0;
	return 1;
}

size_t getPoolCount_Village(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_1_1) return 0;
	return 1;
}

size_t getPoolCount(enum Source source, enum Version version, enum Biome biome) {
	switch (source) {
		case Source_Bonus_Chest: return getPoolCount_BonusChest(version, biome);
		case Source_Desert_Pyramid: return getPoolCount_DesertPyramid(version, biome);
		case Source_Fortress: return getPoolCount_Fortress(version, biome);
		case Source_Jungle_Temple_Trap: return getPoolCount_JungleTempleTrap(version, biome);
		case Source_Jungle_Temple_Treasure: return getPoolCount_JungleTempleTreasure(version, biome);
		case Source_Mineshaft: return getPoolCount_Mineshaft(version, biome);
		case Source_Monster_Room: return getPoolCount_MonsterRoom(version, biome);
		case Source_Stronghold_Chest_Corridor: return getPoolCount_StrongholdChestCorridor(version, biome);
		case Source_Stronghold_Library: return getPoolCount_StrongholdLibrary(version, biome);
		case Source_Stronghold_Room_Crossing: return getPoolCount_StrongholdRoomCrossing(version, biome);
		case Source_Village: return getPoolCount_Village(version, biome);
		default: return 0;
	}
}