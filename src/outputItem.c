#include "outputItem.h"

void lootAttributes_none(Item *const item, PRNG *const prng) {
	(void)prng;
	if (!item) return;
	// Right now item->attributes has a memory leak. However, this particular attempt to fix that breaks the program...
	// if (item->attributesCount && item->attributes) {
	// 	free(item->attributes);
	// 	item->attributes = NULL;
	// }
	item->attributesCount = 0;
}

void lootAttributes_discType(Item *const item, PRNG *const prng) {
	if (!item || !prng) return;
	if (!item->attributesCount || !item->attributes) item->attributes = (int *)calloc(1, sizeof(int));
	else if (item->attributesCount < 1 && item->attributes) item->attributes = (int *)realloc(item->attributes, 1);
	if (!item->attributes) return;
	item->attributesCount = 1;
	item->attributes[item->attributesCount - 1] = !abstractNextInt(prng, 2) ? Attributes_Disc_13 : Attributes_Disc_Cat;
}