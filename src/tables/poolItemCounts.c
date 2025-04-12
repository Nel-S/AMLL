#include "poolItemCounts.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t getPoolItemCounts_MonsterRoom(size_t poolNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0:
			if (version < Infdev_20100625_1917) return 0;
			if (version < Alpha_1_0_1_01) return 8;
			if (version < Alpha_1_0_14) return 9;
			if (version < Beta_1_4) return 10;
			return 11;
		default: return 0;
	}
}

size_t getPoolItemCounts(size_t poolNumber, enum Structure structure, enum Version version, enum Biome biome) {
	switch (structure) {
		case Structure_Monster_Room: return getPoolItemCounts_MonsterRoom(poolNumber, version, biome);
		default: return 0;
	}
}

#ifdef __cplusplus
}
#endif