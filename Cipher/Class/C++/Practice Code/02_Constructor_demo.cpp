#include <iostream> 

class Date 
{
    public: 
        Date()
        {
            std::cout   << "----Entered Date::Date()-----" << std::endl; 
            std::cout   << "Date::Date():Address of object to be initialized:" 
                        <<  std::dec << this << std::endl; 
            std::cout   << "----Leaving Date::Date()----" << std::endl; 
        }
}; 

void test();

int main() 
{
    std::cout <<    "----Entered main()----" << std::endl; 
    Date myDate1; 
    Date myDate2; 

    std::cout   << "&myDate1:" << std::dec << &myDate1 << std::endl
                << "&myDate2:" << std::dec << &myDate2 << std::endl; 

    test(); 
    std::cout <<  "----Leaving main()----" << std::endl; 
    return (0); 
}

void test() 
{
    std::cout << "----Entered test()----" << std::endl; 
    Date X, Y, Z; 
    std::cout   << "X:" << std::dec << &X << std::endl
                << "Y:" << std::dec << &Y << std::endl
                << "Z:" << std::dec << &Z << std::endl; 
    std::cout << "----Leaving test()----" << std::endl;  
}