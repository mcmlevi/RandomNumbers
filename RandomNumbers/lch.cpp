#include "lch.h"

uint64_t lch::random()
{
	_prev = (_multiplier * _prev + _increment) % _seed;
	return _prev;
}

void lch::seed(uint64_t seed)
{
	_seed = seed;
}
