// !Dynamic Memory Allocation
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
/*
    int *p{nullptr};
    p = new int;
    *p = 10; // Stored in heap
    cout << *p << "\n";
    delete p; // ? free the memory allocated to p
    cout << *p << "\n";
    p = nullptr; // Always do this
    
    int *q {new int(20)};
    int *r {new int{20.6}}; // Prevents narrowing conversion ie casting
    cout << q << "\n";
    cout << *q << "\n";
    delete q; // ! dont delete memory twice
    q = nullptr;

    /*
    Dangling pointer:
    Uninitialized pointer
    Deleded pointer
    Multiple pointer pointing to same memory location
    



    // Master and Slave pointers

    int *p8{new int{10}};
    int *p9{p8};

    cout << *p8 << "\n";
    cout << *p9 << "\n";
    delete p8; 
    p8 = nullptr;
    cout << *p9 << "\n"; // Dangling pointer
    delete p9;
    p9 = nullptr; 
*/

    // When new fails

    // for (size_t i {0}; i < 100; i++)
    // {
    //     try
    //     {
    //         int* n {new int[10000000000]};
    //     }
    //     catch(std::exception& ex)
    //     {
    //         cout << ex.what() << "\n";
    //     }
    // }
    
    

    // OR
    // for (size_t i = 0; i < 100; i++)
    // {
        
    // int *n {new (std::nothrow) int[10000000000]};
    // if(n == nullptr)
    // {
    //     cout<< "Memory allocation failed\n";
    // }
    // else
    // {
    //     cout<<"Memory allocation successful\n";
    // }
    
    // }
    

    // ! Null Poiter Safety

    // int *p10{nullptr};
    // if(p10)
    // {
    //     cout << *p10 << "\n";
    // }
    // else
    // {
    //     cout << "p10 is a null pointer\n";
    // }

    // delete p10; // this is safe

    // int *p11{new int{51}};

    // //should delete p11 

    // p11 = new int{52}; // Memory leak


    // {
    //     int *p12{new int{10}};
    // }
    //  Memory leak :: out of scope




}

