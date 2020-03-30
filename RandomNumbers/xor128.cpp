#include "xor128.h"
#include "xor32.h"

void xor128::seed(uint64_t seed)
{
	xor32 tempRandomGenerator;
	tempRandomGenerator.seed(seed);

	for (int i = 0; i < 4; ++i)
	{
		xor128State[i] =static_cast<uint32_t>(tempRandomGenerator.random());
	}
	
}

uint64_t xor128::random()
{
	/* Algorithm "xor128" from p. 5 of Marsaglia, "Xorshift RNGs" */
	uint32_t t = xor128State[3];

	uint32_t const s = xor128State[0];
	xor128State[3] = xor128State[2];
	xor128State[2] = xor128State[1];
	xor128State[1] = s;

	t ^= t << 11;
	t ^= t >> 8;
	return xor128State[0] = t ^ s ^ (s >> 19);
}
