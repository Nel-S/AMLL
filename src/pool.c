#include "pool.h"

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

size_t getPoolCount(enum Structure structure, enum Version version, enum Biome biome) {
	switch (structure) {
		case Structure_Mineshaft: return getPoolCount_Mineshaft(version, biome);
		case Structure_Monster_Room: return getPoolCount_MonsterRoom(version, biome);
		case Structure_Stronghold_Library: return getPoolCount_StrongholdLibrary(version, biome);
		case Structure_Stronghold_Room_Crossing: return getPoolCount_StrongholdRoomCrossing(version, biome);
		default: return 0;
	}
}