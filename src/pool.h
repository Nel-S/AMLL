#ifndef _AMLL_POOL_H
#define _AMLL_POOL_H

#include "entry.h"

STRUCT(LootPool) {
	int minRolls, maxRolls, summedWeight;
	LootEntry *entries;
	size_t entryCount;
};

#ifdef __cplusplus
extern "C" {
#endif

// Returns how many loot pools exist within the current structure/version/biome's loot table.
size_t getPoolCount(enum Structure structure, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif