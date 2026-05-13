#include <iostream>
#include "const.h"
#include "cylinder.cpp"
using namespace std;

int main()
{
    Cylinder c(10, 11);
    c.vol();

    Cylinder *p_c = &c;

    /* cout << (*p_c).vol() << "\n";
    cout << p_c->vol() << "\n"; */


    // by using heap
    Cylinder *c1 = new Cylinder(10, 11);
    cout << c1->vol() << "\n";
    delete c1;
}