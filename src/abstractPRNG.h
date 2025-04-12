#ifndef _AMLL_ABSTRACT_PRNG_H
#define _AMLL_ABSTRACT_PRNG_H
#include "enums.h"
#include "../Chunkbiomes/Brng.h"

typedef uint64_t Random;

STRUCT(PRNG) {
	enum PRNGType type;
	union {
		Random random;
		MersenneTwister mersenneTwister;
		Xoroshiro xoroshiro;
	};
};

#ifdef __cplusplus
extern "C" {
#endif

void abstractSetSeed(PRNG *const prng, uint64_t seed, int numberOfCalls);

int abstractNextInt(PRNG *const prng, int bound);

float abstractNextFloat(PRNG *const prng);

#ifdef __cplusplus
}
#endif

#endif