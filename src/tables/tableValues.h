#ifndef _AMLL_TABLE_VALUES_H
#define _AMLL_TABLE_VALUES_H

#include "itemAttributes.h"

STRUCT(LootItem) {
	int type;
	int weight, rarity, minCount, maxCount;
	lootAttributes *setAttributes;
};

STRUCT(LootPool) {
	int minRolls, maxRolls, summedWeight;
	LootItem *lootItems;
	size_t lootItemsCount;
};

STRUCT(LootTable) {
	LootPool *pools;
	size_t poolsCount;
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