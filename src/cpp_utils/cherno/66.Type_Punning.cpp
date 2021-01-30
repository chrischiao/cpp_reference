#include "pch.h"

namespace ns66
{
	struct Entity
	{
		int x, y;

		int* GetPositions()
		{
			return &x;
		}
	};
}

void test_66()
{
	using namespace ns66;

	Entity e = { 5, 8 };

	//int* position = (int*)&e;

	//int y = *(int*)((char*)&e + 4);
	//std::cout << y << std::endl;

	int* position = e.GetPositions();
	position[0] = 2;
	std::cout << position[0] << ", " << position[1] << std::endl;
}