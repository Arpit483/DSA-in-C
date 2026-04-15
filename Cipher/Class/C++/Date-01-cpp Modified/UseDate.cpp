#include "Date.hpp"

void testDate();

int main()
{
    testDate();
    return 0;
}

void testDate()
{
    Date *p_date = allocateDate(9, 4, 2026);
    //p_date->day = 18;
    p_date->setDay(p_date, 18);
    p_date->showDate(p_date);


}