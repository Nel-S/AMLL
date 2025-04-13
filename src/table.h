#ifndef _AMLL_TABLE_H
#define _AMLL_TABLE_H

#include "pool.h"

STRUCT(LootTable) {
	LootPool *pools;
	size_t poolCount;
	int prngType;
};

#ifdef __cplusplus
extern "C" {
#endif

bool addLootToTable_MonsterRoom(enum Version version, enum Biome biome, LootTable *const lootTable);

bool addLootToTable(enum Structure structure, enum Version version, enum Biome biome, LootTable *const lootTable);


#ifdef __cplusplus
}
#endif

#endif