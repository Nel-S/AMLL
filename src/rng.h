#ifndef AMLL_RNG_H
#define AMLL_RNG_H
#include "enums.h"
#include "../Chunkbiomes/Brng.h"
// #include <stdio.h>

// Not strictly related to RNGs, but it needs to go somewhere and enums.h didn't seem right
static inline size_t resizeArray(void *array, size_t newCapacity, size_t elementSize, bool first) {
	size_t bytesCount = elementSize*newCapacity;
	// printf("%zd\n", bytesCount);
	if (!bytesCount || bytesCount < newCapacity) return 0;
	array = first ? calloc(newCapacity, elementSize) : realloc(array, bytesCount);
	return array ? newCapacity : 0;
}

typedef uint64_t Random;

STRUCT(RNG) {
	enum RngType type;
	union {
		Random random;
		MersenneTwister mersenneTwister;
		Xoroshiro xoroshiro;
	};
};

#ifdef __cplusplus
extern "C" {
#endif

void generalizedSetSeed(RNG *const rng, uint64_t seed, int numberOfCalls);

int generalizedNextInt(RNG *const rng, int bound);

float generalizedNextFloat(RNG *const rng);

#ifdef __cplusplus
}
#endif

#endif