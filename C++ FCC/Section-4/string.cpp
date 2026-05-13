#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include<ctype.h>

using namespace std;

int main()
{
    /*
    // !alpha numercic
    string str1{"Hello"};

    if(std::isalnum(str1[0]))
    {
        cout<<"First character is alphanumeric"<<endl;
    }
    else
    {
        cout<<"First character is not alphanumeric"<<endl;
    }
    

    if(std::isalnum(')'))
    {
        cout<<"First character is alphanumeric"<<endl;
    }
    else
    {
        cout<<"First character is not alphanumeric"<<endl;
    }

 !! for alphabtic use isalpha

    

    string str1{"Hello there we are Jonny Liver"};
    int blank = 0;
    for (size_t i = 0; i < size(str1); i++)
    {
        if(std::isblank(str1[i]))
        {
            blank++;
        }
    }
    cout << blank << "\n";

    

    //! Lenght of string

    const char msg[]{"Hello there we are Jonny Liver"};
    cout<<std::strlen(msg)<<"\n";
    cout << size(msg) << "\n";
    cout << sizeof(msg) << "\n";

    cout << "\n";
    const char *msg1{"Hello there we are Shakira"};
    cout<<std::strlen(msg1)<<"\n";
    cout << sizeof(msg1) << "\n";
    cout<<"\n";
    
    
    
    const char* st{"Hello"};
    const char* st1{"Bello"};

    cout<<std::strcmp(st,st1)<<"\n";
    st1[0] = 'Y'; // ERROR 
    st1 =  "Hello";
    cout<<std::strcmp(st,st1)<<"\n";

    std::strchr(st,'o'); // returns pointer to first occurrence of 'o' in st
    std::strcat(st,st1); // concatenates st1 to st, but st is a pointer to a string literal which is read-only, so this will cause undefined behavior


    */


    //! String class

    std::string str1{"Hello"};
    std::string str2{str1};
    std::string str3{"Hello there" , 4};
    std::string str4(4, 'a' );
    std::string str5{"Hello there" , 4 , 7};
    str2 = "Bello"; // It clears the memory of str2 and assign new value to it
    cout<<str1<<"\n";
    cout<<str2<<"\n";
    cout<<str3<<"\n";
    cout<<str4<<"\n";
    cout<<str5<<"\n";

    

}