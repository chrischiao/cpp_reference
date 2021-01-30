#include "pch.h"

#define TEST(desc) void test_##desc();\
void test() { test_##desc(); }

//TEST(dllFunc)
TEST(85)

int main()
{
	test();
}