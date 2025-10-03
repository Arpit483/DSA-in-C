#include <stdio.h>

void right_shift_positive(int arr[] , int n);
void display_array(int arr[] , int size);

int main (void)
{
    int array[] = {-2 , -4 , 5,  6 , 7, 8 , 2};
    int size = sizeof(array) / sizeof(array[0]);

    right_shift_positive(array , size);
    display_array(array , size);


}

void right_shift_positive(int arr[] , int n)
{
    int tmp = arr[n - 1] ;
    int i = n - 2;
    
    while (i >= 0 && arr[i] > 0)
        {
            arr[i + 1] = arr[i];
            i = i - 1 ;
        }
    arr[i + 1] = tmp;

}

void display_array(int arr[] , int size) // Function Defination
{
    int i = 0;

    while (i < size)
        {
            printf( " {%d: %d} "  , i ,  arr[i]);
            i = i + 1;
        }   
    printf("\n");
    
}