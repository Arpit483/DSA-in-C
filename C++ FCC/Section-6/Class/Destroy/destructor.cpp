#include <iostream>
using namespace std;

class Dog{
    public:
        Dog() = default;
        Dog(string_view c_name, int c_age , string_view c_breed);
        ~Dog();

    private:
        string name;
        string breed;
        int *p_age{nullptr};
};
Dog::Dog(string_view c_name, int c_age , string_view c_breed){
    name = c_name;
    p_age = new int;
    *p_age = c_age;
    breed = c_breed;
    cout << name << endl;
}
Dog::~Dog(){
    delete p_age;
    cout << name << endl;
}


int main(){

    Dog d1("Doggy1",25,"male" );
    Dog d2("Doggy2",25,"male" );
    Dog d3("Doggy3",25,"male" );
    Dog d4("Doggy4",25,"male" );
    Dog d5("Doggy5",25,"male" );

    cout << "END" << endl;
    return 0;
}