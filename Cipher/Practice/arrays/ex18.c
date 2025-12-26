//reaggrange such tha even is befor odd

#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int arr[] = {12,7,3,8,15,4,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int i = 0;

    while(i < size ){

        int j = i + 1;

        if(arr[i] % 2 != 0){
            
            while( j < size){
                if(arr[j] % 2 == 0){
                    swap(&arr[i] , &arr[j]);
                    break;
                }
                j++;
            }

        }
        i++;

    }

     for (int k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}