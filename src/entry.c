#include "entry.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t getEntryCount_Mineshaft(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Version_Beta_1_8) return 0;
			return 10;
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

size_t getEntryCount(size_t poolNumber, enum Structure structure, enum Version version, enum Biome biome) {
	switch (structure) {
		case Structure_Mineshaft: return getEntryCount_Mineshaft(poolNumber, version, biome);
		case Structure_Monster_Room: return getEntryCount_MonsterRoom(poolNumber, version, biome);
		case Structure_Stronghold_Library: return getEntryCount_StrongholdLibrary(poolNumber, version, biome);
		case Structure_Stronghold_Room_Crossing: return getEntryCount_StrongholdRoomCrossing(poolNumber, version, biome);
		default: return 0;
	}
}

#ifdef __cplusplus
}
#endif