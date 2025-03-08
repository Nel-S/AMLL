#ifndef AMLL_LOOT_H
#define AMLL_LOOT_H
#include "src/lootAttributes.h"

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
	int rngType;
};

static const int MAX_CHEST_CAPACITY = 27;

#ifdef __cplusplus
extern "C" {
#endif

bool constructLootTable(int structure, int version, int biome, LootTable *lootTable);

bool freeLootTable(LootTable *lootTable);

ssize_t getLoot(const LootTable *const lootTable, uint64_t lootSeed, Item *const output, size_t outputCapacity);

#ifdef __cplusplus
}
#endif

#endif