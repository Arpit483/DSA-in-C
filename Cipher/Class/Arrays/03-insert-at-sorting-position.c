#include <stdio.h>

void insert (int arr[] , int n);
void display_array(int arr[] , int size);

int main (void) 
{

    int arr[] = {5,10,20,30,40,50,60,15};

    insert(arr , 8);
    display_array(arr , 8);

}


void insert (int arr[] , int n)
{
    int i = n - 2 , tmp = arr[n - 1];
    while (i > 0 && arr[i] > tmp)
    {
        arr[i + 1] = arr[i];
        i = i - 1;
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