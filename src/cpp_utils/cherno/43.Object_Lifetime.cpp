#include "pch.h"
#include <memory>

namespace ns43
{
	class Entity
	{
	public:
		Entity()
		{
			std::cout << "Created Entity!" << std::endl;
		}

		~Entity()
		{
			std::cout << "Destroyed Entity!" << std::endl;
		}

		void Print()
		{
			std::cout << "printing..." << std::endl;
		}

		void Print2() const
		{
			std::cout << "const func" << std::endl;
		}
		};


	class ScopedPtr
	{
	private:
		Entity* m_Ptr;
	public:
		ScopedPtr(Entity* ptr)
			: m_Ptr(ptr)
		{
		}

		~ScopedPtr()
		{
			delete m_Ptr;
		}

		Entity* operator->()
		{
			return m_Ptr;
		}

		const Entity* operator->() const
		{
			return m_Ptr;
		}
	};


	template<class T>
	class Shared_Ptr
	{
	private:
		int* m_Count;
		T* m_obj;
	public:
		Shared_Ptr(T* obj)
			: m_obj(obj), m_Count(new int(1))
		{
		}

		Shared_Ptr(Shared_Ptr<T> const& ins)
		{
			this->operator=(ins);
		}

		~Shared_Ptr()
		{
			if (m_obj && !--m_Count[0])
			{
				delete m_obj;
				delete m_Count;
			}
		}

		T* operator->()
		{
			return m_obj;
		}

		Shared_Ptr<T>* operator=(const Shared_Ptr<T>& ins)
		{
			m_Count = ins.m_Count;
			m_obj = ins.m_obj;
			++(*m_Count);
			return this;
		}
	};


	void Print()
	{
		std::cout << "----------------------------------" << std::endl;
	}

}

void test_43()
{
	using namespace ns43;

	{
		Entity e;
	}
	Print();

	{
		//Entity* e = new Entity();
		ScopedPtr e = new Entity();
		e->Print();
		const ScopedPtr p = new Entity();
		p->Print2();
	}
	Print();

	{
		Shared_Ptr<Entity> sp(new Entity());
		sp->Print();
	}
	Print();

	// unique_ptr
	{
		std::unique_ptr<Entity> pEntity = std::make_unique<Entity>();
		//std::unique_ptr<Entity> p = pEntity; // unique_ptr(const unique_ptr&) = delete; 
												  // unique_ptr& operator=(const unique_ptr&) = delete;
		pEntity->Print();
	}
	Print();

	// shared_ptr
	{
		std::shared_ptr<Entity> sp;
		{
			std::shared_ptr<Entity> spEntity = std::make_shared<Entity>();
			sp = spEntity;
		}
		sp->Print();
	}
	Print();

	// weak_ptr
	{
		std::weak_ptr<Entity> p;
		{
			std::shared_ptr<Entity> spEntity = std::make_shared<Entity>();
			p = spEntity;
		}
		std::cout << p.expired() << std::endl;
	}
	Print();
}