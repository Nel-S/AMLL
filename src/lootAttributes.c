#include "lootAttributes.h"

void lootAttributes_noOp(Item *const item, RNG *const rng) {
	(void)item;
	(void)rng;
	return;
}

void lootAttributes_discType(Item *const item, RNG *const rng) {
	if (!(item->attributesCount = resizeArray(item->attributes, item->attributesCount + 1, sizeof(*item->attributes), !item->attributesCount))) return;
	item->attributes[item->attributesCount - 1] = !generalizedNextInt(rng, 2) ? Attributes_Disc_13 : Attributes_Disc_Cat;
}