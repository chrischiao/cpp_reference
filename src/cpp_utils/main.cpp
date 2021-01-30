#include "pch.h"

#define TEST(desc) void test_##desc();\
void test() { test_##desc(); }

//TEST(dllFunc)
TEST(68)

int main()
{
	test();
}