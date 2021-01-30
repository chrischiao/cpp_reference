#include "pch.h"

namespace ns25
{
	class Example
	{
	public:
		Example()
		{
			std::cout << "Created Example" << std::endl;
		}

		Example(int x)
		{
			std::cout << "Created Example with " << x << "!" << std::endl;
		}
	};

	class Entity
	{
	public:
		float X, Y;
	private:
		std::string m_Name;
		Example m_Example;

	public:
		Entity()
			: X(0.0f), Y(0.0f), m_Name("unknown"), m_Example(8) // member initializer list
		{
			std::cout << "Created Entity!" << std::endl;
		}

		Entity(float x, float y)//: X(x), Y(y)
		{
			X = x;
			Y = y;
			m_Name = "unknown";
			m_Example = Example(8); // init twice
			std::cout << "Created Entity!" << std::endl;
		}

		~Entity()
		{
			std::cout << "Destroyed Entity!" << std::endl;
		}

		void Print()
		{
			std::cout << X << ", " << Y << std::endl;
		}
	};


	class Log
	{
		//private:
		//	Log() {}
	public:
		Log() = delete;

		static void Write()
		{

		}
	};
}

void test_25()
{
	using namespace ns25;

	{
		Entity e(10.0f, 5.0f);
		e.Print();
		//e.~Entity();
	}
	std::cout << "-------------------------" << std::endl;
	{
		Entity e2;
	}

	Log::Write();
	//Log l;
}