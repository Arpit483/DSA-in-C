#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    public:
        Person(const std::string &name_param, int age_param);

        void print_info()const
        {
            std::cout << full_name << " (" << age << ")\n";
        }
    private:
        std::string full_name;
        int age;

    public:
        static int person_count;
};


#endif