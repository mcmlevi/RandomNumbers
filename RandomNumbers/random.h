#pragma once
#include "randInterface.h"
#include "lch.h"
#include "xor32.h"
#include "xor64.h"
#include "xor128.h"

namespace ldk
{
	class randomDevice
	{
	public:
		enum class DEVICE
		{
			LCG,
			XOR32,
			XOR64,
			XOR128
		};

		randomDevice(DEVICE type = DEVICE::LCG);
		~randomDevice();
		void seed(__int64 seed);
		uint64_t rand();
	private:

		randInterface* _interface{ nullptr };

		DEVICE _type{};
	};

	inline randomDevice::randomDevice(DEVICE type)
	{
		_type = type;
		switch (_type) {
		case DEVICE::LCG:
			_interface = new lch();
			break;
		case DEVICE::XOR32:
			_interface = new xor32();
			break;
		case DEVICE::XOR64:
			_interface = new xor64();
			break;
		case DEVICE::XOR128:
			_interface = new xor128();
			break;
		default:
			_interface = nullptr;
			break;
		}
	}

	inline randomDevice::~randomDevice()
	{
		delete _interface;
		_interface = nullptr;
	}

	inline void randomDevice::seed(long long seed)
	{
		_interface->seed(seed);
	}

	inline uint64_t randomDevice::rand()
	{
		return _interface->random();
	}
}
