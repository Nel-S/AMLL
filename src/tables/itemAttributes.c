#include "itemAttributes.h"

void lootAttributes_none(Item *const item, PRNG *const prng) {
	(void)prng;
	if (!item) return;
	item->attributesCount = 0;
}

void lootAttributes_discType(Item *const item, PRNG *const prng) {
	if (!item || !prng) return;
	++item->attributesCount;
	item->attributes = (int *)(item->attributesCount > 1 && item->attributes ? realloc(item->attributes, item->attributesCount) : calloc(item->attributesCount, sizeof(int)));
	if (!item->attributes) return;
	item->attributes[item->attributesCount - 1] = !abstractNextInt(prng, 2) ? Attributes_Disc_13 : Attributes_Disc_Cat;
}