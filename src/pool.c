#include "pool.h"

size_t getPoolCount_MonsterRoom(enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Infdev_20100625_1917) return 0;
	return 1;
}

size_t getPoolCount(enum Structure structure, enum Version version, enum Biome biome) {
	switch (structure) {
		case Structure_Monster_Room: return getPoolCount_MonsterRoom(version, biome);
		default: return 0;
	}
}