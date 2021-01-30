#include "pch.h"
#include <vector>

namespace ns47
{
	struct Vertex
	{
		float x, y, z;
	};

	std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
	{
		stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
		return stream;
	}

	void Function(const std::vector<Vertex>& vectices)
	{

	}
}

void test_47()
{
	using namespace ns47;

	std::vector<Vertex> vertices;
	vertices.push_back({ 1.0f, 2.0f, 3.0f });
	vertices.push_back({ 4.0f, 5.0f, 6.0f });
	Function(vertices);

	for (int i = 0;i < vertices.size();i++)
		std::cout << vertices[i] << std::endl;
	for (Vertex v : vertices) // copy
		std::cout << v << std::endl;
	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	vertices.erase(vertices.begin() + 1);
	for (Vertex& v : vertices)
		std::cout << v << std::endl;
}