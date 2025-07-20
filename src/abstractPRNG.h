#ifndef _AMLL_ABSTRACT_PRNG_H
#define _AMLL_ABSTRACT_PRNG_H
#include "../enums.h"
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

// Seeds the provided PRNG.
void abstractSetSeed(PRNG *const prng, uint64_t seed, int numberOfCalls);

/* Returns the next integer in the range [0, `bound` - 1] from the provided PRNG.
   `bound` must be non-negative.*/
int abstractNextInt(PRNG *const prng, int bound);

// Returns the next single-precision float in the range [0, 1 - 1/2^24] from the provided PRNG.
float abstractNextFloat(PRNG *const prng);

#ifdef __cplusplus
}
#endif

#endif