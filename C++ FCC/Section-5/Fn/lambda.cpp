#include <iostream>
using namespace std;


/* // Lambda fn Signature
auto func = []()
{
    cout << "Hello Lambda";
};

[]()
{
    cout << "Hello Lambda -> no name ";
}();

[](double a , double b)
{
    cout << (a+b);
}(12.7 , 115.2);

[](double a, double b)
{
    return a+b;
}(12.7, 115.2);

auto res = []((double a , double b)-> double)
{
    return (a+b);
}(12.7, 115.2);
 */


 int main()
{
/* 
    auto hello = []()
    {
        cout << "HEllo lamba" << "\n";
    };

    []()
    {
        cout << "HEllo lamba" << "\n";
    }();

    hello();

     */

    

    /* cout<<[](double a, double b)
    {
        return a+b;
    }(12.7, 115.2)<<endl; */

    /* cout<< [](double a, double b)->double
    {
        return a + b;
    }(12.7, 115.2)<<endl; */


    // Capture list 

    // Capture by value

    int c{45};
    /* auto func = [c]()
    {
        cout << c << "\n";
    };

    for (size_t i = 0; i < 5; i++)
    {
        ++c;
        func();
    }
    
    // Capture by reference
    cout << endl;

    auto func1 = [&c]()
    {
        cout << c << "\n";
    };

    for (size_t i = 0; i < 5; i++)
    {
        ++c;
        func1();
    }

    cout << endl; 
    */
    // For all 
    // by value
    auto func1 = [=]()
    {
        cout << c << "\n";
    };



    // Capture all by reference
    auto func2 = [&]()
    {
        ++c;
        cout << c << "\n";
    };
    func1();
    func2();
}