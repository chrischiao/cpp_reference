#include "pch.h"

namespace ns67
{
	struct Vector2
	{
		float x, y;
	};

	/*struct Vector4
	{
		float x, y, z, w;

		Vector2& GetA()
		{
			return *(Vector2*)&x;
		}
	};*/

	struct Vector4
	{
		union
		{
			struct
			{
				float x, y, z, w;
			};
			struct
			{
				Vector2 a, b;
			};
		};
	};

	void PrintVector2(const Vector2& vector)
	{
		std::cout << vector.x << ", " << vector.y << std::endl;
	}
}

void test_67()
{
	using namespace ns67;

	/*struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << ", " << u.b << std::endl;*/

	Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
	PrintVector2(vector.a);
	PrintVector2(vector.b);
	vector.z = 500.0f;
	std::cout << "----------------------\n";
	PrintVector2(vector.a);
	PrintVector2(vector.b);
}