#include<stdio.h>
#include<string.h>

// Sum of n 

int sum_n(int n)
{
    int sum = 0;
    while(n  > 0){
        sum = sum + n;
        n--;
        sum_n(n);
    }
    return sum;
}

// Factorial

int fact(int n)
{
    if (n <= 1)
        return 1;

    return n * fact(n - 1);
}


// Digits in a number

int digits_no(int n)
{
    if (n == 0)
        return 0;

    return 1 +  digits_no(n / 10);
}

// Sum of digits

int sum_of(int n)
{
    if(n == 0)
        return 0;

    return (n % 10) + sum_of(n / 10) ;

}

// Reverse a no

int rev(int n)
{
    int dig = 0;
    if(n == 0)
        return 0;

    if(dig == 0)
    {
    }
}

// check palindrome







int main(){

    printf("%s" , "Enter a Number: ");
    int n;
    scanf("%d" , &n);
    //printf("%d" , sum_n(4));
    //printf("%d" , fact(4));
    //printf("%d" , digits_no(n));
    //printf("%d" , sum_of(n));
    printf("%d" , rev(n));




}



