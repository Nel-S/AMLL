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

size_t getAttributesCapacity(int poolNumber, int entryNumber, enum Source source, enum Version version, enum Biome biome);

#ifdef __cplusplus
}
#endif

#endif