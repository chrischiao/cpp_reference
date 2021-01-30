#include "pch.h"
#include <array>
#include <algorithm>

namespace ns57
{
    void printArray(const std::array<int, 5>& n)
    {
        std::cout << "length: " << n.size() << std::endl;

        for (int j = 0; j < n.size(); j++)
        {
            std::cout << "n[" << j << "] = " << n[j] << std::endl;
        }

    }

    template <size_t N>
    void print_array(const std::array<int, N>& array) {
        for (auto& i : array)
            std::cout << i << std::endl;
    }

    template<std::size_t SIZE>
    void mulArray(std::array<int, SIZE>& arr, const int multiplier)
    {
        for (auto& e : arr)
        {
            e *= multiplier;
        }
    }

    inline void print_line()
    {
        std::cout << "--------------------------\n";
    }
}

#define PRINT_LINE() std::cout << "--------------------------\n"

void test_57()
{
    using namespace ns57;

	// std::array
	std::array<int, 5> data;
	data[0] = 2;
	data[4] = 1;
    //data[5] = 1;

	int dataOld[5];
	dataOld[0] = 0;
    //dataOld[5] = 1;

    std::array<int, 5> data1{ {1, 2, 3, 4, 5} };                           
    std::array<int, 3> data2 = { 1, 2, 3 };

    printArray(data1);
    PRINT_LINE();
    print_array(data2);
    PRINT_LINE();
    mulArray(data1, 5);
    printArray(data1);
    PRINT_LINE();
    
#pragma region cppreference
    // construction uses aggregate initialization
    std::array<int, 3> a1{ {1, 2, 3} }; // double-braces required in C++11 prior to the CWG 1270 revision
                                        // (not needed in C++11 after the revision and in C++14 and beyond)
    std::array<int, 3> a2 = { 1, 2, 3 };  // never required after =
    std::array<std::string, 2> a3 = { std::string("a"), "b" };

    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(),
        std::ostream_iterator<int>(std::cout, " "));

    std::cout << '\n';

    // ranged for loop is supported
    for (const auto& s : a3)
        std::cout << s << ' ';
#pragma endregion

    std::cout << std::endl;
    PRINT_LINE();
}