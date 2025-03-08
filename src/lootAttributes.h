#ifndef AMLL_LOOT_ATTRIBUTES_H
#define AMLL_LOOT_ATTRIBUTES_H

#include "rng.h"

STRUCT(Item) {
	int type, count, chestIndex;
	int *attributes;
	size_t attributesCount;
};

// Syntax from Cubiomes
typedef void (lootAttributes)(Item *const, RNG *const);

#ifdef __cplusplus
extern "C" {
#endif

void lootAttributes_noOp(Item *const item, RNG *const rng);

void lootAttributes_discType(Item *const item, RNG *const rng);

#ifdef __cplusplus
}
#endif

#endif