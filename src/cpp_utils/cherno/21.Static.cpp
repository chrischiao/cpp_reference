#include "pch.h"

extern int s_Variable;

void Function21()
{

}


struct Entity
{
	static int x, y;

	static void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x;
int Entity::y;


void Function23()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}


class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance;
		return instance;
	}

	void Hello()
	{
		std::cout << "hello" << std::endl;
	}
};


#if 0
int main()
#else
int main21()
#endif
{
	std::cout << s_Variable << std::endl;


	Entity::Print();

	Entity::x = 5;
	Entity::y = 8;

	Entity::Print();


	Function23();
	Function23();
	Function23();
	Function23();
	Function23();


	Singleton::Get().Hello();


	std::cin.get();

	return 0;
}