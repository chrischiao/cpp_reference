#include "pch.h"

namespace ns82
{
	class Singleton
	{
	public:
		Singleton(const Singleton&) = delete;

		static Singleton& Get()
		{
			return s_Instance;
		}

		void Function() {}

	private:
		Singleton() {}

		float m_Member = 0.0f;

		static Singleton s_Instance;
	};

	Singleton Singleton::s_Instance;


	// Random class
	class Random
	{
	public:
		Random(const Random&) = delete;

		static Random& Get()
		{
			static Random instance;
			return instance;
		}

		static float Float() { return Get().IFloat(); }
	private:
		float IFloat() { return m_RandomGenerator; }
		Random() {}

		float m_RandomGenerator = 0.5f;

	};
}

namespace RandomClass
{
	static float s_RandomGenerator = 0.5f;
	static float Float() { return s_RandomGenerator; }
}

void test_82()
{
	using namespace ns82;

	//Singleton instance = Singleton::Get();
	Singleton& instance = Singleton::Get();
	auto& instance2 = Singleton::Get();

	instance.Function();

	// Random
	float number = Random::Float();
	std::cout << number << std::endl;
	std::cin.get();

	//// using namespace 
	//float number2 = RandomClass::Float();
	//std::cout << number << std::endl;
	//std::cin.get();
}