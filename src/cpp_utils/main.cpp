#include "pch.h"

#define TEST(desc) void test_##desc();\
void test() { test_##desc(); }

//TEST(dllFunc)
TEST(90)

int main()
{
	test();
}