# include <stdio.h>
#include <string.h>

struct company
{
    int company_code;
    char company_name [20];
    float turnover;
};

int main(void)
{
    struct company c1 = { 1001 , "Infosys" , 3.4};

    struct company c2;
    c2.company_code =4002 ; 
    strcpy(c2.company_name, " TCS " );
    c2.turnover = 2.6;
    
    printf("Company Code : %d\n" , c1.company_code);
    printf("Company Name : %d\n" , c1.company_name);
    printf("Complany Turnover : %0.1f $billion \n\n" , c1.turnover );

    printf("Company Code : %d\n" , c2.company_code);
    printf("Company Name : %d\n" , c2.company_name);
    printf("Complany Turnover : %0.1f $billion \n\n" , c2.turnover );

    return 0;

}

