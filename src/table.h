#ifndef _AMLL_TABLE_H
#define _AMLL_TABLE_H

#include "pool.h"

static const size_t MAX_CHEST_CAPACITY = 27;
static const size_t MAX_DISPENSER_CAPACITY = 9;

STRUCT(LootTable) {
	LootPool *pools;
	size_t poolCount, containerCapacity;
	enum PRNGType prngType;
	enum Source source;
	enum Version version;
};

STRUCT(Item) {
	// int type, count;
	enum ItemType type;
	int count, containerIndex;
	Attribute *attributes;
	size_t attributesCapacity;
	int attributeCount;
};

#ifdef __cplusplus
extern "C" {
#endif

// Copies the provided item.
bool copyItem(const Item *const oldItem, Item *const newItem);

// Adds the loot attributes to the provided loot table.
bool addLootToTable(LootTable *const lootTable, enum Source source, enum Version version, enum Biome biome);


#ifdef __cplusplus
}
#endif

#endif