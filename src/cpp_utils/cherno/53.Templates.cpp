#include "pch.h"

namespace ns53
{
    template<typename T>
    void Print(T value)
    {
        std::cout << value << std::endl;
    }

    template<int N>
    class Array
    {
    private:
        int m_Array[N];
    public:
        int GetSize() const { return N; }
    };

    //class Array
    //{
    //private:
    //    int m_Array[5];
    //public:
    //    int GetSize() const { return 5; }
    //};

    template<typename T, int N>
    class ArrayEx
    {
    private:
        T m_Array[N];
    public:
        int GetSize() const { return N; }
    };

}


#if 0
int main()
#else
int main53()
#endif
{
    using namespace ns53;

    Print(5);
    Print("Hello");
    Print(5.5f);


    Array<5> array;
    std::cout << array.GetSize() << std::endl;

    ArrayEx<std::string, 50> arrayEx;
    std::cout << arrayEx.GetSize() << std::endl;

    MAIN_END
}