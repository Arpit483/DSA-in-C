#include "cylinder.h"

Cylinder::Cylinder (double r , double ht)
{
    b_r = r;
    h = ht;
}

double Cylinder::vol(){
    return PI * pow(b_r, 2) * h;
}

double Cylinder::get_b_r(){
    return b_r;
}
double Cylinder::get_h(){
    return h;
}

// Setters
void Cylinder::set_b_r(double set_r){
    b_r = set_r;
}
void Cylinder::set_h(double set_h){
    h = set_h;
}