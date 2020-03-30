#pragma once
#include <cstdint>

class randInterface
{
public:
	randInterface() = default;
	~randInterface() = default;
	virtual void seed(uint64_t seed) = 0;
	virtual uint64_t random() = 0;
};

