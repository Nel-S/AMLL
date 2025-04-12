#ifndef _AMLL_POOL_ITEM_COUNTS_H
#define _AMLL_POOL_ITEM_COUNTS_H

#include "../enums.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t getPoolItemCounts_MonsterRoom(size_t poolNumber, enum Version version, enum Biome biome);

size_t getPoolItemCounts(size_t poolNumber, enum Structure structure, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif