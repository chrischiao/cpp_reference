#include "pch.h"
#include "AppVersion.h"
#include "MathLibrary.h"

#pragma comment(lib, "MathLibrary" __PRODUCT_VERSION _LIB_PLATFORM _PROJECT_CONFIGURATION ".lib")
#pragma message ("Automatically linking MathLibrary" __PRODUCT_VERSION _LIB_PLATFORM _PROJECT_CONFIGURATION ".lib")


#if 1
int main()
#else
int main0()
#endif
{
	std::cout << "hello" << std::endl;

    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": "
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 <<
        " Fibonacci sequence values fit in an " <<
        "unsigned 64-bit integer." << std::endl;

	std::cin.get();
	return 0;
}