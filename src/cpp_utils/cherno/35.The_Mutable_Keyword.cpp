#include "pch.h"
#include <string>

namespace ns35
{
	class Entity
	{
	private:
		std::string m_Name;
		mutable int m_DebugCount = 0; // use in class

	public:
		const std::string& GetName() const
		{
			m_DebugCount++;
			return m_Name;
		}
	};

}

void test_35()
{
	using namespace ns35;

	const Entity e;
	e.GetName();


	// use in lambda
	int x = 8;
	std::cout << x << std::endl;
	auto f = [=]() mutable
	{
		x++;
		std::cout << x << std::endl;
	};
	f();
	std::cout << x << std::endl;
}