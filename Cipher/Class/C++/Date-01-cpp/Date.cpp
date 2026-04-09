#include "Date.hpp"
#include <stdio.h>
#include <stdlib.h>

Date* allocateDate(int day, int month, int year)
{
    Date *p_new_date = (Date*) malloc (sizeof(Date));
    if(NULL ==  p_new_date){
        fprintf(stderr, "allocateDate() -> malloc(): out of memory");
        return NULL;
    }

    p_new_date->day = day;
    p_new_date->month = month;
    p_new_date->year = year;

    return p_new_date;
}

void releaseDate(Date **pp_date)
{
    free(*pp_date);
    *pp_date = NULL;
}

int getDay(Date *p_date)
{
    return p_date->day;
}

int getMonth(Date *p_date)
{
    return p_date->month;
}

int getYear(Date *p_date)
{
    return p_date->year;
}

void setDay(Date *p_date, int day)
{
    p_date->day = day;
}

void setMonth(Date *p_date, int month)
{
    p_date->month = month;
}

void setYear(Date *p_date, int year)
{
    p_date->year = year;
}

void showDate(Date *p_date)
{
    if(p_date != NULL)
    {
        fprintf(stdout, "day: %d\n", p_date->day);
        fprintf(stdout, "month: %d\n", p_date->month);
        fprintf(stdout, "year: %d\n", p_date->year);
    }
}