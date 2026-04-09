#include<stdio.h>
#include <stdlib.h>

struct date{
    int day;
    int month;
    int year;
};

void test();
struct Date* allocateDate(int day, int month, int year);
void testDate();

int main()
{
    struct date mydate;
    mydate.day = 8;
    mydate.month = 8;
    mydate.year = 2005;

    test();
    testDate()

    return 0;
}


void test()
{
    struct date *p_date = (struct date *) malloc(sizeof(struct date));

    if(NULL == p_date) {
        fprintf(stderr, "test(): fatal: outof memory");
        exit(EXIT_FAILURE);
    }

    p_date->day = 1;
    p_date->month = 2;
    p_date->year = 2005;

    fprintf(stdout, " in test() Date: %d/%d/%d\n", p_date->day, p_date->month, p_date->year);

    free(p_date);
    p_date = NULL;

    return;
}


void testDate(struct date D)
{
    
    void testDate();
    D->mydate = allocateDate(09, 04, 2026);
    mydate->date = 18;
}

 