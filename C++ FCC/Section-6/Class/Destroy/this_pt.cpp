#include <iostream>
using namespace std;

class Dog{
    public:
        Dog() = default;
        Dog(const string &c_name, int c_age , const string &c_breed);
        ~Dog();

        Dog* set_name(const string& name)
        {
            this->name = name;
            return this;
        }

        Dog* age(int age)
        {
            *(this->p_age) = age;
            return this;
        }
    private:
        string name;
        string breed;
        int *p_age{nullptr};
};
Dog::Dog(const string &c_name, int c_age , const string &c_breed){
    name = c_name;
    p_age = new int;
    *p_age = c_age;
    breed = c_breed;
    cout << name <<" Address "<<this<< endl;
}
Dog::~Dog(){
    delete p_age;
    cout << name << endl;
}
// Struct only has public by default but class has private by default    

int main(){

    Dog d1("Doggy1",25,"male" );
    Dog d2("Doggy2",25,"male" );
    Dog d3("Doggy3",25,"male" );
    Dog d4("Doggy4",25,"male" );
    Dog d5("Doggy5",25,"male" );
    //cout << sizeof(string) << endl;
    //cout << sizeof(int) << endl;
    cout << sizeof(d5) << endl; // sum of size of variables in class
    

    // p_dog->set_name("hello")->set_age(5);

    cout << "END" << endl;
    return 0;
}