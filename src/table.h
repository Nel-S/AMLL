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

// Adds the loot attributes to the provided loot table.
bool addLootToTable(LootTable *const lootTable, enum Structure structure, enum Version version, enum Biome biome);


#ifdef __cplusplus
}
#endif

#endif