#include "xor32.h"

void xor32::seed(uint64_t seed)
{
	xor32State =static_cast<uint32_t>(seed);
}

uint64_t xor32::random()
{
	uint32_t x = xor32State;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return xor32State = x;
}
