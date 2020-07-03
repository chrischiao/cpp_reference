#include "pch.h"
#include <thread>

static bool s_Finished = false;

namespace ns62
{
	void DoWork()
	{
		using namespace std::literals::chrono_literals;

		std::cout << "working thread id = " << std::this_thread::get_id() << std::endl;

		while (!s_Finished)
		{
			std::cout << "working...\n";
			std::this_thread::sleep_for(1s);
		}
	}
}


#if 0
int main()
#else
int main62()
#endif
{
	using namespace ns62;

	std::thread worker(DoWork);

	std::cin.get();
	s_Finished = true;

	worker.join();
	std::cout << "Finished." << std::endl;
	std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;

	MAIN_END
}