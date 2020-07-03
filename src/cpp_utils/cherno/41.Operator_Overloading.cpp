#include "pch.h"

namespace ns41
{
	struct Vector2
	{
		float x, y;

		Vector2(float x, float y)
			: x(x), y(y)
		{
		}

		Vector2 Add(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator+(const Vector2& other)
		{
			return Add(other);
		}

		Vector2 Multiply(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}

		Vector2 operator*(const Vector2& other)
		{
			return Multiply(other);
		}

		bool operator==(const Vector2& other) const
		{
			return x == other.x && y == other.y;
		}

		bool operator!=(const Vector2& other) const
		{
			//return !operator==(other);
			return !(*this == other);
		}
	};

	std::ostream& operator<<(std::ostream& stream, const Vector2& vertex)
	{
		stream << vertex.x << ", " << vertex.y;
		return stream;
	}
}


#if 0
int main()
#else
int main41()
#endif
{
	using namespace ns41;

	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position + speed * powerup;

	Vector2 position2(4.0f, 4.1f);
	if (position == position2)
	{
	}

	std::cout << result1 << std::endl;


	MAIN_END
}