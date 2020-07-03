#include "pch.h"
#include <vector>

namespace ns48
{
	struct Vertex
	{
		float x, y, z;

		Vertex(float x, float y, float z)
			: x(x), y(y), z(z)
		{
		}

		Vertex(const Vertex& vertex)
			: x(vertex.x), y(vertex.y), z(vertex.z)
		{
			std::cout << "Copied!" << std::endl;
		}
	};
}


#if 0
int main()
#else
int main48()
#endif
{
	using namespace ns48;

	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(1.0f, 2.0f, 3.0f));
	vertices.push_back(Vertex(4.0f, 5.0f, 6.0f));
	vertices.push_back(Vertex(7.0f, 8.0f, 9.0f));

	std::cout << "optimization result:" << std::endl;

	std::vector<Vertex> vertices2;
	vertices2.reserve(3);
	vertices2.emplace_back(1.0f, 2.0f, 3.0f);
	vertices2.emplace_back(4.0f, 5.0f, 6.0f);
	vertices2.emplace_back(7.0f, 8.0f, 9.0f);


	MAIN_END
}