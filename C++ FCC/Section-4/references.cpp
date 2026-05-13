#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
/*
    // ! reference

    int a{45};
    double b{3.14};

    int &ref_a{a};
    double &ref_b{b};

    cout<<a<<" "<<ref_a<<endl;
    cout<<b<<" "<<ref_b<<endl;
//    cout<<a<<" "<<*ref_a<<endl;
//    cout<<b<<" "<<*ref_b<<endl;
    cout<<a<<" "<<&ref_a<<endl;
    cout<<b<<" "<<&ref_b<<endl;
    cout<<&a<<" "<<sizeof(&ref_a)<<endl;
    cout<<&b<<" "<<sizeof(&ref_b)<<endl;
 

    int a{12};
    int &ref_a{a};
    cout<<a<<" "<<ref_a<<endl;

    ref_a++;
    cout<<a<<" "<<ref_a<<endl;
    */

    int a{12};
    const int &ref_a{a};
    cout<<a<<" "<<ref_a<<endl;

    // ref_a++; // This would cause a compile error since ref_a is a const reference
    cout<<a<<" "<<ref_a<<endl;

    const int *const ptr_a{&a}; // pointer to a const int no shuch thing for refernce
    cout<<*ptr_a<<" "<<ptr_a<<endl;
    
}