#include "pch.h"

#include "AppVersion.h"
#include "MathLibrary.h"

#pragma comment(lib, "MathLibrary.lib")
#pragma message ("Automatically linking MathLibrary.lib")


void test_dllFunc()
{
    fibonacci_init(1, 1);
    do
    {
        std::cout << fibonacci_index() << ": " << fibonacci_current() << std::endl;
    } while (fibonacci_next());

    std::cout << fibonacci_index() + 1 << " Fibonacci sequence values fit in an unsigned 64-bit integer.\n";
}