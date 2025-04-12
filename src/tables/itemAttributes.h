#ifndef _AMLL_ITEM_ATTRIBUTES_H
#define _AMLL_ITEM_ATTRIBUTES_H

#include "../abstractPRNG.h"

STRUCT(Item) {
	int type, count, chestIndex;
	int *attributes;
	size_t attributesCount;
};

// Syntax from Cubiomes
typedef void (lootAttributes)(Item *const, PRNG *const);

#ifdef __cplusplus
extern "C" {
#endif

void lootAttributes_none(Item *const item, PRNG *const prng);
void lootAttributes_discType(Item *const item, PRNG *const prng);

#ifdef __cplusplus
}
#endif

#endif