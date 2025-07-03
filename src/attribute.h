#ifndef _AMLL_ATTRIBUTE_H
#define _AMLL_ATTRIBUTE_H

#include "abstractPRNG.h"

STRUCT(Attribute) {
	enum AttributeName name;
	int level, maxLevel;
};

#ifdef __cplusplus
extern "C" {
#endif

bool copyAttribute(const Attribute *const oldAttribute, Attribute *const newAttribute);

size_t getAttributesCapacity(int poolNumber, int entryNumber, enum Source source, enum Version version, enum Biome biome);

size_t copyEnchantments(Attribute *const output, size_t outputSize, int poolNumber, int entryNumber, enum Source source, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif