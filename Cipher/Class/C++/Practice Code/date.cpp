#include <iostream>

class Date{
    private:
        int date;
        int month;
        int year;

    public:
        void init(int dd, int mm, int yy);
        this->date = dd;
        this->month = mm;
        this->year = yy;

    int getDate()
    {
        return this->date;
    }
    int getMonth()
    {
        return this->month
    }
    int getYear()
    {
        return this->year
    }

    int setDate()
    {
        int dd;
        this->date  =date;
    }
    int setMonth()
    {
        int mm;
        this->year  =year;
    }
    int setYear()
    {
        int yy;
        this->year  =year;
    }
    

    void showDate(){}
};

void test_date();

int mainn()
{
    test_day();
    return 0;
}

void test_day()
{
    Date mydate;
    mydate.init(25, 1, 2026);
    int day = mydate.getDate();
    int month = mydate.getMonth();
    int year = mydate.getYear();
}

std::cout("----Date individula Components are : Day" << std::endl);
std::cout("----Date individula Components are : Day" << std::endl);
std::cout("----Date individula Components are : Day" << std::endl);
mydate.setDate(08);
mydate.setMonth(02);
mydate.setYear(26);

mydate.show(08);