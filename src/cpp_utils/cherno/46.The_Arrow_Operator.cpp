#include "pch.h"

namespace ns46
{
	struct Vector3
	{
		float x, y, z;
	};
}

void test_46()
{
	using namespace ns46;

	int xOffset = (int)&((Vector3*)nullptr)->x;
	int yOffset = (int)&((Vector3*)nullptr)->y;
	int zOffset = (int)&((Vector3*)nullptr)->z;

	std::cout << xOffset << std::endl;
	std::cout << yOffset << std::endl;
	std::cout << zOffset << std::endl;
}