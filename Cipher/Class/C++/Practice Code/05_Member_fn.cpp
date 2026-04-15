#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day, int init_month, int init_year);
        int getDay();
        int getMonth();
        int getYear();

        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);

        void show();
};

/*
? This will be a global C like function ! We don't want this
? What do we want? We want to implement member function of class Date 

int getDay() 
{

}
*/

Date::Date(int init_day, int init_month, int init_year)
{
    this->day = init_day;
    this->month = init_month;
    this->year = init_year;
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}
int Date::getYear()
{
    return this->year;
}

void Date::setDay(int newDay)
{
    this->day = newDay;
}

void Date::setMonth(int newMonth)
{
    this->month = newMonth;
}

void Date::setYear(int newYear)
{
    this->year = newYear;
}

void Date::show()
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}

int main()
{
    Date myDate(31, 01, 2026);

    myDate.show();
    myDate.setMonth(04);
    myDate.show();

    int year = myDate.getYear();

    std::cout<< "Year " << year << std::endl;
}
