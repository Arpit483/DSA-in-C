# include <stdio.h>

void display_array(int arr[] , int size); // Function Decleration

int main (void)
{
    int array[] = {1, 2, 3, 4, 6, 7, 9};
    
    //size of array 
    int arrayLength = sizeof(array) / sizeof(array[0]);


    printf("Array Before Shifting Positive Numbers To Right \n");
    display_array(array , arrayLength);  // Function Calling

    int temp = array[arrayLength  - 1 ];
    int i = arrayLength - 1 ;
    while (i >= 0)
    {
        array[i + 1] = array[i];
        i = i - 1;
    }
    array[0] = temp;
    
    printf("Array After Shifting Positive Numbers To Right \n");
    display_array(array , arrayLength);

}

void display_array(int arr[] , int size) // Function Defination
{
    int i = 0;

    while (i < size)
    {
        printf( " {%d: %d} "  , i ,  arr[i]);
        i++;
    }
    printf("\n");
    
}