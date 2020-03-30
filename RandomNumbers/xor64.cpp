#include "xor64.h"

void xor64::seed(uint64_t seed)
{
	xor64State = seed;
}

uint64_t xor64::random()
{
	return xorShift64();
}

uint64_t xor64::xorShift64()
{
	uint64_t x = xor64State;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return xor64State = x;
}
