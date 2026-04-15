#include <iostream>

class Date
{
    public:
    Date()
    {
        std::cout << "In Date::Date()" << std::endl;
    }
};

void test();

int main()
{
    Date myDate1;
    Date myDate2;
    test();
    return (0);
}

void test()
{
    Date X, Y, Z;
}