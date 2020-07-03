#include "pch.h"
#include <chrono>
#include <array>

namespace ns74
{
	class Timer
	{
	public:
		Timer()
		{
			m_StartTimepoint = std::chrono::high_resolution_clock::now();
		}

		~Timer()
		{
			Stop();
		}

		void Stop()
		{
			auto endTimepoint = std::chrono::high_resolution_clock::now();

			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

			auto duration = end - start;
			double ms = duration * 0.001;

			std::cout << duration << "us (" << ms << "ms)\n";
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
	};
}


#if 0
int main()
#else
int main74()
#endif
{
	using namespace ns74;

	int value = 0;
	{
		Timer timer;
		for (int i = 0;i < 1000000;i++)
			value += 2;
	}
	std::cout << value << std::endl;

	MAIN_END
}