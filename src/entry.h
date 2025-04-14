#ifndef _AMLL_ENTRY_H
#define _AMLL_ENTRY_H

#include "attribute.h"

STRUCT(LootEntry) {
	enum ItemType type;
	int minCount, maxCount, weight, rarity;
	Attribute *possibleAttributes;
	size_t possibleAttributeCapacity;
	int minPossibleAttributes, maxPossibleAttributes;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Returns how many entries exist within the current source-of-loot/version/biome's `poolNumber`-th loot pool.
   This is not the summed weight of the loot pool's entries, which is instead added in table.c.*/
size_t getEntryCount(size_t poolNumber, enum Source source, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif