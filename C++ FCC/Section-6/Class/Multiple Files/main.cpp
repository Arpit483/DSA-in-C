#include <iostream>
#include "cylinder.cpp"
using namespace std;

int main()
{
    Cylinder c1(10, 10);
    cout << c1.vol() << "\n";
}