#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n1 = 15; 
    int n2 = 017; //Octal
    int n3 = 0x0F; // HeaxDecimal
    int n4 = 0b00001111; // Binary
    int n5{10}; // braced initialization
    int n6(20);
    auto a = 50;

    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;
    cout << n5 << endl;
    cout << n6 << endl;
    cout << a << endl;
    cout << sizeof(a) << endl;

    

    // -------------------------------------------

    float p1{1.2344456789998765456787654f};
    double p2{1.2354678565453336675645354656453423256};
    long double p3{1.234567876435456789767646474677456645237865467L};

    cout<< sizeof(p1) << endl;
    cout<< sizeof(p2) << endl;
    cout<< sizeof(p3) << endl;

    cout << setprecision(20);
    cout<< (p1) << endl;
    cout<< (p2) << endl;
    cout << (p3) << endl;

    // double p6{76827653287871566886};
    // cout << p6 << endl;

    double p6{7682765e-11};
    cout << p6 << endl;

    cout << "--------------------------------------" << endl;

    bool red{false};
    bool gre{true};

    cout << red << endl;
    cout << gre << endl;

    cout << boolalpha;
    cout << red << endl;
    cout << gre << endl;
}
