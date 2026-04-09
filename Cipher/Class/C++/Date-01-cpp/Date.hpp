#ifndef DATE_HPP
#define DATE_HPP

class Date 
{
private:
    int day;
    int month;
    int year;

public:
    int getDay(Date *p_date);
    int getMonth(Date *p_date);
    int getYear(Date *p_date);

    void setDay(Date *p_date, int day);
    void setMonth(Date *p_date, int month);
    void setYear(Date *p_date, int year);

    void showDate(Date *p_date);
};

Date* allocateDate(int day, int month, int year);
void releaseDate(Date **pp_date);

int getDay(Date *p_date);
int getMonth(Date *p_date);
int getYear(Date *p_date);

void setDay(Date *p_date, int day);
void setMonth(Date *p_date, int month);
void setYear(Date *p_date, int year);

void showDate(Date *p_date);

#endif