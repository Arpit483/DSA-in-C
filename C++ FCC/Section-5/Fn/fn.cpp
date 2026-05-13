#include "person.h"
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int Person::person_count{8};

Person::Person(const std::string &name_param, int age_param)
    : full_name{name_param}, age{age_param}{
        ++person_count;
    }

int main()
{
    // !Functions and class

    Person p1{"John Doe", 30};
    p1.print_info();
}