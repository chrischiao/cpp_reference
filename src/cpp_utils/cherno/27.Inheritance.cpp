#include "pch.h"

namespace ns27
{
	// Interface in c++
	class Printable
	{
	public:
		virtual std::string GetClassName() = 0; // pure virtual function
	};

	class Entity : public Printable
	{
	public:
		int X, Y;

		void Move(int xa, int ya)
		{
			X += xa;
			Y += ya;
		}

		/*virtual*/ std::string GetName() { return "Entity"; }
		std::string GetClassName() override { return "Entity"; }

	public:
		Entity()
		{
			X = 0;
			Y = 0;
		}
	};

	class Player : public Entity
	{
	public:
		float m_speed;

		void SetSpeed(float speed)
		{
			m_speed = speed;
		}

		std::string GetName() /*override*/ { return "Player"; }
		std::string GetClassName() override { return "Player"; }

	public:
		Player()
		{
			m_speed = 1.0f;
		}
	};

	class A : public Printable
	{
	public:
		//std::string GetClassName() override { return "A"; }
	};



	void PrintName(Entity* entity)
	{
		std::cout << entity->GetName() << std::endl;
	}

	void Print(Printable* obj)
	{
		// the 'Printable' type guarantee that the obj has this certain function 'GetClassName'
		std::cout << obj->GetClassName() << std::endl;
	}
}


#if 0
int main()
#else
int main27()
#endif
{
	using namespace ns27;

	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl;

	Entity* e = new Entity();
	PrintName(e);
	Player* p = new Player();
	PrintName(p);

	std::cout << "------------------" << std::endl;

	Print(e);
	Print(p);

	//A a;
	//Print(&a);

	delete e;
	delete p;

	MAIN_END
}