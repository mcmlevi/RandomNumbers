#pragma once
#include "randInterface.h"
class xor32:public randInterface
{
public:
	void seed(uint64_t seed) override;
	uint64_t random() override;

private:
	uint32_t xor32State{};
};

