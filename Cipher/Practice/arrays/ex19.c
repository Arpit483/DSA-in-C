// Check if the array is sorted or not


#include<stdio.h>


int main(){
    int arr[] = {1,2,6,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    while (i < size - 1)
    {
        if(arr[i] > arr[i + 1] ){
            printf("%s" , "Not Sorted");
            return 0;
        }
        i++;
    }
    

    printf("Sorted");
    return 0;

}