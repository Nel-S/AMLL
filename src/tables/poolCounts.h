#ifndef _AMLL_POOL_COUNTS_H
#define _AMLL_POOL_COUNTS_H

#include "../enums.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t getPoolsCount_MonsterRoom(enum Version version, enum Biome biome);

size_t getPoolsCount(enum Structure structure, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif