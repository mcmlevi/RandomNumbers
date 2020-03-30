#pragma once
#include "randInterface.h"
class lch: public randInterface
{
public:
	uint64_t random() override;
	void seed(uint64_t seed) override;
private:
	__int64 _seed{ 1 };
	__int64 _multiplier{ 214013 };
	__int64 _increment{ 2531011 };
	__int64 _prev{};
};

