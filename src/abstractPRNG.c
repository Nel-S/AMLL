#include "abstractPRNG.h"

void abstractSetSeed(PRNG *const prng, uint64_t seed, int numberOfCalls) {
	switch (prng->type) {
		case PRNG_java_util_Random:
			setSeed(&prng->random, seed);
			return;
		case PRNG_Mersenne_Twister:
			mSetSeed(&prng->mersenneTwister, seed, numberOfCalls);
			return;
		case PRNG_Xoroshiro128_Plus_Plus:
			xSetSeed(&prng->xoroshiro, seed);
			return;
	}
}

int abstractNextInt(PRNG *const prng, int bound) {
	switch (prng->type) {
		case PRNG_java_util_Random: return nextInt(&prng->random, bound);
		case PRNG_Mersenne_Twister: return mNextInt(&prng->mersenneTwister, bound);
		case PRNG_Xoroshiro128_Plus_Plus: return xNextInt(&prng->xoroshiro, bound);
	}
	return -1;
}

float abstractNextFloat(PRNG *const prng) {
	switch (prng->type) {
		case PRNG_java_util_Random: return nextFloat(&prng->random);
		case PRNG_Mersenne_Twister: return mNextFloat(&prng->mersenneTwister);
		case PRNG_Xoroshiro128_Plus_Plus: return xNextFloat(&prng->xoroshiro);
	}
	return -1.;
}