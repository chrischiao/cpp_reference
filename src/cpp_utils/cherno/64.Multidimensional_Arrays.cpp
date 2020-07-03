#include "pch.h"

#if 0
int main()
#else
int main64()
#endif
{
	int** a2d = new int* [5];
	for (int i = 0;i < 5;i++)
		a2d[i] = new int[5];

	for (int y = 0;y < 5;y++)
	{
		for (int x = 0;x < 5;x++)
		{
			a2d[x][y] = 5 - y;
		}
	}

	for (int y = 0;y < 5;y++)
	{
		for (int x = 0;x < 5;x++)
		{
			std::cout << a2d[x][y] << "\t";
		}
		std::cout << "\n";
	}

	for (int i = 0;i < 5;i++)
		delete[] a2d[i];
	delete[] a2d;

	std::cout << "-------------------------------------\n";

	int* array = new int[5 * 5];
	for (int y = 0;y < 5;y++)
	{
		for (int x = 0;x < 5;x++)
		{
			array[x + y * 5] = y + 1;
		}
	}

	for (int y = 0;y < 5;y++)
	{
		for (int x = 0;x < 5;x++)
		{
			std::cout << array[x + y * 5] << "\t";
		}
		std::cout << "\n";
	}

	delete[] array;

	MAIN_END
}