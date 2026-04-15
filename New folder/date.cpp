#include <iostream>
#include <stdio.h>

class Date{
    private:
        int date;
        int month;
        int year;

    public:
        void init(int dd, int mm, int yy){
        this->date = dd;
        this->month = mm;
        this->year = yy;
    }
    int getDate()
    {
        return this->date;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }

    void setDate(int date)
    {
        this->date  =date;
    }
    void setMonth(int month)
    {
        this->month  =month;
    }
    void setYear(int year)
    {
        this->year  =year;
    }
    
    void showDate()
    {
        std::cout << date << "/" << month << "/" << year << std::endl;
    }
};

void test_date();

int main()
{
    test_date();
    return 0;
}

void test_date()
{
    Date mydate;
    mydate.init(25, 1, 2026);
    int date = mydate.getDate();
    int month = mydate.getMonth();
    int year = mydate.getYear();


    std::cout << "----------------\nDate individual components are: " << date << "/" << month << "/" << year << std::endl;
    mydate.setDate(8);
    mydate.setMonth(2);
    mydate.setYear(26);

    mydate.showDate();

}