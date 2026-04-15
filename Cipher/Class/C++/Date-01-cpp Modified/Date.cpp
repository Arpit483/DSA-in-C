#include "Date.hpp"
#include <iostream>
#include <cstdlib>

Date* allocateDate(int day, int month, int year)
{
    Date *p_new_date = (Date*) malloc (sizeof(Date));
    if(NULL ==  p_new_date){
        fprintf(stderr, "allocateDate() -> malloc(): out of memory");
        return NULL;
    }

   p_new_date->setDay(p_new_date, day);
   p_new_date->setMonth(p_new_date, month);
   p_new_date->setYear(p_new_date, year);

    return p_new_date;
}

void releaseDate(Date **pp_date)
{
    free(*pp_date);
    *pp_date = NULL;
}

int Date::getDay(Date *p_date)
{
    return p_date->day;
}

int Date::getMonth(Date *p_date)
{
    return p_date->month;
}

int Date::getYear(Date *p_date)
{
    return p_date->year;
}

void Date::setDay(Date *p_date, int day)
{
    p_date->day = day;
}

void Date::setMonth(Date *p_date, int month)
{
    p_date->month = month;
}

void Date::setYear(Date *p_date, int year)
{
    p_date->year = year;
}

void Date::showDate(Date *p_date)
{
    if(p_date != NULL)
    {
        fprintf(stdout, "day: %d\n", getDay(p_date));
        fprintf(stdout, "month: %d\n", getMonth(p_date));
        fprintf(stdout, "year: %d\n", getYear(p_date));
    }
}