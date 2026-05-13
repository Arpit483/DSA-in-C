#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int *pt{};
    int *pt2{nullptr}; // ? use nullptr instead of NULL or 0 for better readability and type safety
    int a = 4;
    int *addr {&a}; // ? address of operator & gives the memory address of variable a
    

    cout << sizeof(pt) << "\n";
    cout << sizeof(pt2) << "\n";
    cout << sizeof(a) << "\n";
    cout << "Address of a: " << addr << "\n";
    cout << "Value at addr: " << *addr << "\n"; // Deferencing
    */

    // ! Character Pointers

    const char *name {"Name"}; // ? string literal is stored in read only memory and we should not modify it, so we use const char* to point to it
    cout << name << "\n";
    cout << *name << "\n";

    //! Allow user to modify string literal
    char name2[] {"Name"};
    name2[0] = 'M';
    cout << name2 << "\n";

    //! iterating
    const char *p{name};
    while(*p!= '\0')
    {
        cout << *p << "\n";
        p++;
    }
}