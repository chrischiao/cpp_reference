#include "pch.h"
#include <chrono>
//#include <thread>

namespace ns63
{
	struct S_Timer
	{
		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;

		S_Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}

		~S_Timer()
		{
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;

			float ms = duration.count() * 1000.0f;
			std::cout << "Timer took " << ms << "ms" << std::endl;
		}
	};

	void Function()
	{
		S_Timer timer;

		for (int i = 0;i < 100;i++)
			std::cout << "Hello" << std::endl; //std::cout << "Hello\n";
	}
}

void test_63()
{
	using namespace ns63;

	Function();
}
