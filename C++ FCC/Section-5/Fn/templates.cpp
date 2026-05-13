#include <iostream>
using namespace std;

//T max(T a, T b); // They are just blueprints not real cpp code

template <typename T>
T maxxie(T a, T b);
// &T maxxie(T &a, T &b);

//template <>
//const char *maxxie<const char *>(const char *a, const char *b){
// return (std::strcmp(a, b)>0) ? a : b ;
// }

int main()
{
    int a{10};
    int b{20};
    double aa{10.10};
    double bb{20.20};
    string s{"Hello"};
    string s2{"Bello"};

    cout<<maxxie(a, b)<<"\n";
    cout<<maxxie(aa, bb)<<"\n";
    cout<<maxxie(s, s2)<<"\n";

    // When done with pointer it causes disasters


    // Explicit declerations
    cout<<maxxie<int>(a, b)<<"\n";
    cout<<maxxie<double>(aa, bb)<<"\n";
    cout<<maxxie<string>(s, s2)<<"\n";

    // const char *g{"Jello"};
    // const char *f{"Bello"};
}

template <typename T> 
T maxxie(T a, T b){
    return (a > b) ? a : b;
}