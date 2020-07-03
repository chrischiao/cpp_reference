#include "pch.h"
#include <vector>
#include <algorithm>
#include <functional>

namespace ns59
{
	static void ForEach(const std::vector<int>& values, void(*func)(int))
	{
		for (int value : values)
			func(value);
	}

	void ForEachEx(const std::vector<int>& values, const std::function<void(int)>& func)
	{
		for (int value : values)
			func(value);
	}
}


#if 0
int main()
#else
int main59()
#endif
{
	using namespace ns59;

	std::vector<int> values = { 1,5,4,2,3 };
	auto lambda = [](int value) {std::cout << "Value: " << value << std::endl;};
	ForEach(values, lambda);

	int a = 5;
	auto lambdaEx = [=](int value) {std::cout << "Value: " << a << std::endl;};
	ForEachEx(values, lambdaEx);

	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3;});
	std::cout << *it << std::endl;

	MAIN_END
}