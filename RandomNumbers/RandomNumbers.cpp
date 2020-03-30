// RandomNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "random.h"
#include <ctime>

int main()
{
	ldk::randomDevice device(ldk::randomDevice::DEVICE::XOR32);
	device.seed(time(NULL));
	int array[100]{};
	
	for (int i = 0; i < 10'000'000 ; ++i)
	{
		array[device.rand() % 100] ++;
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << i << " : " << array[i]<<"\n";
	}
}


