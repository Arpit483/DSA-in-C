#include <stdio.h>

int main (){


// | -> is a bitwise or operator
// & -> is a bitwise and operator

// ^ -> is a xor operator can be used for swapping

int a , b , c;

a = 5;
b =6;

a = a^b;
b = a^b;
a = a^b;


printf("%d \n" , a);
printf("%d \n" , b);


    int res = 25 | 15 ; 
    int and = 25 & 15 ; 
    
    printf("%d \n" , res);
    printf("%d \n" , and);
    
    return 0;

}