#ifndef CYLINDER_H
#define CYLINDER_H
#include "const.h"

class Cylinder{
    private:
        double b_r{1};
        double h{1};
    public:
        //constructor
        Cylinder() = default;
        Cylinder(double r, double ht);
        //Getter
        double get_b_r();
        double get_h();
        // Setters
        void set_b_r(double set_r);
        void set_h(double set_h);
        //Function
        double vol();
};

#endif