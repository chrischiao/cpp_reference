#include "pch.h"

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;


#if 0
void* operator new(size_t size)
{
	//std::cout << "Allocating " << size << " bytes\n";
	s_AllocationMetrics.TotalAllocated += size;

	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	//std::cout << "Freeing " << size << " bytes\n";
	s_AllocationMetrics.TotalFreed += size;

	free(memory);
}

//void operator delete(void* memory)
//{
//	free(memory);
//}
#endif


static void PrintMemoryUsage() 
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}


namespace ns84
{
	struct Object
	{
		int x, y, z;
	};
}


void test_84()
{
	using namespace ns84;

	//Object* obj = new Object();

	PrintMemoryUsage();
	std::string string = "Cherno";
	PrintMemoryUsage();
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

}