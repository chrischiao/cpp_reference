#include "pch.h"

namespace ns89
{
#define RVALUE_AND_MOVE 0

	class String
	{
	public:
		String() = default;

		String(const char* string)
		{
			printf("Created!\n");
			m_Size = strlen(string);
			m_Data = new char[m_Size];
			memcpy(m_Data, string, m_Size);
		}

		String(const String& other)
		{
			printf("Copied!\n");
			m_Size = other.m_Size;
			m_Data = new char[m_Size];
			memcpy(m_Data, other.m_Data, m_Size);
		}

#if RVALUE_AND_MOVE
		String(String&& other) noexcept
		{
			printf("Moved!\n");
			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Data = nullptr;
			other.m_Size = 0;
		}
#endif

		~String()
		{
			printf("Destroyed!\n");
			delete[] m_Data;
		}

		void Print()
		{
			for (uint32_t i = 0; i < m_Size; i++)
				printf("%c", m_Data[i]);

			printf("\n");
		}
	private:
		char* m_Data;
		uint32_t m_Size;
	};

	class Entity
	{
	public:
		Entity(const String& name)
			: m_Name(name)
		{
		}

#if RVALUE_AND_MOVE
		Entity(String&& name)
			: m_Name(std::move(name))
		{
		}
#endif

		void PrintName()
		{
			m_Name.Print();
		}
	private:
		String m_Name;
	};
}

void test_89()
{
	using namespace ns89;

	//Entity entity(String("Cherno")); 
	Entity entity("Cherno");
	entity.PrintName();

	std::cin.get();
}