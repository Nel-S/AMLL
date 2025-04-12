#include "poolCounts.h"

size_t getPoolsCount_MonsterRoom(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Infdev_20100625_1917) return 0;
	return 1;
}

size_t getPoolsCount(enum Structure structure, enum Version version, enum Biome biome) {
	switch (structure) {
		case Structure_Monster_Room: return getPoolsCount_MonsterRoom(version, biome);
		default: return 0;
	}
}