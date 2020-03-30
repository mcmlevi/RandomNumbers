#pragma once
#include "randInterface.h"

class xor128 :
	public randInterface
{
public:
	void seed(uint64_t seed) override;
	uint64_t random() override;

private:

	uint32_t xorShift128();



	uint32_t xor128State[4]{};
};

