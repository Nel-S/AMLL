#ifndef _AMLL_ENTRY_H
#define _AMLL_ENTRY_H

#include "outputItem.h"

STRUCT(LootEntry) {
	int type;
	int weight, rarity, minCount, maxCount;
	lootAttributes *setAttributes;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Returns how many entries exist within the current structure/version/biome's `poolNumber`-th loot pool.
   This is not the summed weight of the loot pool's entries, which is instead added in table.c.*/
size_t getEntryCount(size_t poolNumber, enum Structure structure, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif