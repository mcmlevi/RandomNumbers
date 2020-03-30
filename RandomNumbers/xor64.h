#pragma once
#include "randInterface.h"
class xor64: public randInterface
{
public:
	void seed(uint64_t seed) override;
	uint64_t random() override;
private:
	uint64_t xorShift64();
	uint64_t xor64State{};
};
