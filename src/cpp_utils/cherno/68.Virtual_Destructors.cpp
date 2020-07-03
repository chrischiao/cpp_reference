#include "pch.h"

namespace ns68
{
	class Base
	{
	public:
		Base() { std::cout << "Base Constrcutor\n"; }
		/*virtual*/ ~Base() { std::cout << "Base Destructor\n"; }
	};

	class Derived : public Base
	{
	public:
		Derived() { m_Array = new int[5]; std::cout << "Derived Constructor\n"; }
		~Derived() { delete[] m_Array; std::cout << "Derived Destructor\n"; }
	private:
		int* m_Array;
	};

}

#if 0
int main()
#else
int main68()
#endif
{
	using namespace ns68;

	Base* base = new Base();
	delete base;
	std::cout << "---------------------\n";
	Derived* derived = new Derived();
	delete derived;
	std::cout << "---------------------\n";
	Base* poly = new Derived();
	delete poly;

	MAIN_END
}