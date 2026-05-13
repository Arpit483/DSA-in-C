#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Cylinder{
    private:
        double b_r{1};
        double h{1};
        const double PI = std::acos(-1.0);
    public:
        //constructor
        Cylinder() = default;
        Cylinder (double r , double h)
        {
            b_r = r;
            h = h;
        }
        //Getter
        double get_b_r(){
            return b_r;
        }
        double get_h(){
            return h;
        }

        // Setters
        void set_b_r(double set_r){
            b_r = set_r;
        }
        void set_h(double set_h){
            h = set_h;
        }
        
        double vol(){
            return PI * pow(b_r, 2) * h;
        }
};


int main()
{
    Cylinder c1;
    cout<<c1.get_b_r()<<"\n";
    cout<<c1.get_h()<<"\n";
    c1.set_b_r(5);
    c1.set_h(5);
    cout<<c1.get_b_r()<<"\n";
    cout<<c1.get_h()<<"\n";
}