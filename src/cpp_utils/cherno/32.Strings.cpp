#include "pch.h"
#include <string>


#if 0
int main()
#else
int main32()
#endif
{
	const char* name = "Cherno";
	const wchar_t* name2 = L"CHerno";

	using namespace std::string_literals;

	std::string s = "Cherno"s + " hello";
	std::cout << s << std::endl;

	const char* s1 = R"(Line1
Line2
Line3
Line4)";
	std::cout << s1 << std::endl;

	const char* s2 = "Line1"
		"Line2"
		"Line3";
	std::cout << s2 << std::endl;

	const char* s3 = "Line1\n"
		"Line2\n"
		"Line3\n";
	std::cout << s3 << std::endl;

	MAIN_END
}