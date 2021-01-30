#include "pch.h"

#include <string>

// Small string Optimization in C++

#if 0
void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}
#endif

void test_83()
{
	std::string name = "Cherno";
	//std::string name = "Cherno Small St"; // 15 characters
	//std::string name = "Cherno Small Str";

	std::cin.get();
}