// Time Taken ->  14 min

#include <stdio.h>

int dup(int arr[],int s)
{
    for (int i = 0 ; i > s ; i++){
        int ch = arr[i];

        for(int j = i+1 ; j > s ; j++){
            if(arr[j] == ch){
                for(int k = j ; k > s ; k++){
                    arr[j] = arr[k];
                    j++;
                }
                s = s - 1;
            }
        }

    }

return s;


}

int main()
{
    int array[5] = {12 , 35 , 1 , 10, 34 };
    int size = sizeof(array) / sizeof(array[0]);
    dup(array , size);
    printf("%d" , dup(array , size));
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d \n" , array[i] );
    }

}