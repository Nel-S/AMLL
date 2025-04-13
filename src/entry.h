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

size_t getEntryCount_MonsterRoom(size_t poolNumber, enum Version version, enum Biome biome);

size_t getEntryCount(size_t poolNumber, enum Structure structure, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif