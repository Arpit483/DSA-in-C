#include <iostream>
using namespace std;

void ref_age(int &age);
void swap(int &a, int &b);

int main()
{
    // int a = 14;

    // //cout << *a<< "\n";
    // cout << &a<< "\n";
    // cout << a<< "\n";
    // // pt_age(&a); // pass by pointer
    // cout << a<< "\n";
    // ref_age(a);
    // cout << a<< "\n";

    int a = 10;
    int b = 20;
    cout << a << " " << b << "\n";
    cout << &a << " " << &b << "\n";
    swap(a, b);
    cout << a << " " << b << "\n";
}

/* void age(int age)
{
    ++age;
    cout << "Age in Function: " << age << "\n";
}

*/
/* 
void pt_age(int *age)
{
    cout << "Inside the function" << "\n";
    cout << age<<"\n";
    cout << *age << endl;
    ++(*age);
    cout << *age << endl;
    
} */

void ref_age(int &age)
{
    cout << "Inside the function" << "\n";
    cout << &age << "\n";
    cout << age<<"\n";
    ++age;
    cout << &age << "\n";
    cout << age<<"\n";
}

void swap(int &a, int &b) // Here we are not taking a copy of original value as argument we are taking address as argument which is passed;
{
    cout << a<<" "<< b<<"\n";
    cout << &a<<" "<< &b<<"\n";
    int temp = a;
    a =  b;
    b = temp;
    cout << "After Swap"<<"\n";
    cout << a<<" "<< b<<"\n";
    cout << &a<<" "<< &b<<"\n";
}

/// Function cant be overloaded based on return type like int double .....

