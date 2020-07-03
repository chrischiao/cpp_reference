#include "pch.h"
#include <vector>

namespace ns58
{
	void HelloWorld()
	{
		std::cout << "Hello World!" << std::endl;
	}

	void HelloWorldEx(int a)
	{
		std::cout << "Hello World! value: " << a << std::endl;
	}


	void PrintValue(int value)
	{
		std::cout << "Value: " << value << std::endl;
	}

	void ForEach(const std::vector<int>& values, void(*func)(int))
	{
		for (int value : values)
			func(value);
	}
}


#if 0
int main()
#else
int main58()
#endif
{
	using namespace ns58;

	// 1
	auto function = HelloWorld;

	function();
	function();

	// 2
	void(*cherno)() = HelloWorld;
	cherno();

	// 3
	typedef void(*HelloWorldFunction)();
	HelloWorldFunction function1 = HelloWorld;
	function1();

	// 4
	typedef void(*HelloWorldExFunction)(int);
	HelloWorldExFunction function2 = HelloWorldEx;
	function2(8);
	function2(2);

	// 5
	std::vector<int> values = { 1,5,4,2,3 };
	ForEach(values, PrintValue);

	// 6 lambda
	ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl;});

	MAIN_END
}