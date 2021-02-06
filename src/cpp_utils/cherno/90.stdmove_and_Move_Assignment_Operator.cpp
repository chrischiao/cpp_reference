#include "pch.h"

/*
* STD move is what you want to do when you want to convert an object to be a temporary
*/

namespace ns90
{
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

		String(String&& other) noexcept
		{
			printf("Moved!\n");
			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Data = nullptr;
			other.m_Size = 0;
		}

		String& operator=(String&& other) noexcept
		{
			printf("Moved!\n");

			if (this != &other) // important: dest = std::move(dest);
			{
				delete[] m_Data; // important: without this line we will create a memory leak

				m_Size = other.m_Size;
				m_Data = other.m_Data;

				other.m_Data = nullptr;
				other.m_Size = 0;
			}

			return *this;
		}

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

		Entity(String&& name)
			: m_Name(std::move(name))
		{
		}

		void PrintName()
		{
			m_Name.Print();
		}
	private:
		String m_Name;
	};
}

void test_90()
{
	using namespace ns90;

	//Entity entity("Cherno");
	//entity.PrintName();

#if 0
	String string = "Hello";
	//String dest = string; 
	//String dest = (String&&)string; //String dest((String&&)string);
	String dest = std::move(string); // move constructor
	dest = string;                   // assignment operator
	dest = std::move(string);        // move assignment
#endif

	String apple = "Apple";
	String dest;
	
	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	dest = std::move(apple); //dest.operator=(std::move(apple));

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	std::cin.get();
}