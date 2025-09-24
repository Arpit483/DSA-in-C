#include <stdio.h>
// User Defined Function

/*
Declare 
Define 
Call
*/

void show();  //Declare

// But if fn is defined before main then noo need to expcilitly declare the function

void Wow()  // Define and Declaare
{
    printf("WOW \n");

}

int add(int a, int b){
    int c;
    printf("Enter 2 Numbers");
    // scanf("%d  %d" , &a , &b);
    c = a+b ;
    // printf("%d" , c);
    return c;

}

int main()
{

    show();  // Call
    Wow();
    int ans = add(3 , 4 );
    printf("%d" , ans);

    return 0;
}

void show()  // Define
{
    printf("hi \n");

}

