#include<stdio.h>

int main(){

    int j;  // If not defined it will take a random varible called garbage value
    int i;
    int k;
    printf("Enter 2 values");
    scanf("%d" , &i);    // The "&"" sign gives us the address of the variable
    scanf("%d" , &j);
    k = i + j;
    printf("The Value of addition of %d and %d is %d" , j ,i ,k );  // This is callled as print format
    return 0;

}

