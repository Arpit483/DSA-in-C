#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
const double PI = std::acos(-1.0); //  To get pi we use acos

/* class Cylinder{
    public:
        double base_r{1.0};
        double ht{1.0};

    public:
        double volume(){
            return PI * pow(base_r  ,2) * ht;
        }
}; */

/* class Cylinder{
    private:
        double base_r{1.0};
        double ht{1.0};

    public:
        double volume(){
            return PI * pow(base_r  ,2) * ht;
        }
}; */


// ! Constructors

/* class Cylinder{
    private:
        double base_r{1.0};
        double ht{1.0};

    public:
        Cylinder(){
            base_r = 2.0;
            ht = 2.0;
        };

        Cylinder(double r , double h)
        {
            base_r = r;
            ht = h;
        }

        double volume(){
            return PI * pow(base_r  ,2) * ht;
        }
}; */

//! Default Constructors
class Cylinder{
    private:
        double base_r{1.0};
        double ht{1.0};

    public:
        Cylinder() = default; //! if we dont generate this and pass a constructor then the compiler wont generate a default empty constructor and it will give u errors
        
        Cylinder(double r , double h)
        {
            base_r = r;
            ht = h;
        }

        double volume(){
            return PI * pow(base_r  ,2) * ht;
        }
};


int main()
{
/*     Cylinder c1;
    cout << c1.volume() << "\n";
    c1.base_r = 3;
    c1.ht = 4;

    cout << c1.volume() << "\n";

    Cylinder c2;
    cout << c2.volume() << "\n"; */

/*     Cylinder c1;
    cout << c1.volume() << "\n"; */
    /* c1.base_r = 3;
    c1.ht = 4; */  // Cant change private variables

    Cylinder c1;
    //Cylinder c1(5 , 4);
    cout << c1.volume() << "\n";
    
}