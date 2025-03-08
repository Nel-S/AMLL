#include "rng.h"

void generalizedSetSeed(RNG *const rng, uint64_t seed, int numberOfCalls) {
	switch (rng->type) {
		case RNG_java_util_Random:
			setSeed(&rng->random, seed);
			return;
		case RNG_Mersenne_Twister:
			mSetSeed(&rng->mersenneTwister, seed, numberOfCalls);
			return;
		case RNG_Xoroshiro128_Plus_Plus:
			xSetSeed(&rng->xoroshiro, seed);
			return;
	}
}

int generalizedNextInt(RNG *const rng, int bound) {
	switch (rng->type) {
		case RNG_java_util_Random: return nextInt(&rng->random, bound);
		case RNG_Mersenne_Twister: return mNextInt(&rng->mersenneTwister, bound);
		case RNG_Xoroshiro128_Plus_Plus: return xNextInt(&rng->xoroshiro, bound);
	}
	return -1;
}

float generalizedNextFloat(RNG *const rng) {
	switch (rng->type) {
		case RNG_java_util_Random: return nextFloat(&rng->random);
		case RNG_Mersenne_Twister: return mNextFloat(&rng->mersenneTwister);
		case RNG_Xoroshiro128_Plus_Plus: return xNextFloat(&rng->xoroshiro);
	}
	return -1.;
}