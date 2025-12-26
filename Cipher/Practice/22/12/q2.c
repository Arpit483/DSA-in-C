// Time Taken ->  14 min

#include <stdio.h>

int sl(int arr[],int s)
{
int a = 0;
int greatest = 0;
  for (int i = 0 ; i < s ; i++){
    
    if (greatest < arr[i]){
        greatest = arr[i];
    }
  }
int sg = 0;
  for (int j = 0 ; j < s ; j++){
 
    if(sg < arr[j] &&  arr[j] != greatest){
        sg = arr[j];
    }
}

return sg;
}

int main()
{
    int array[5] = {12 , 35 , 1 , 10, 34 };
    
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d \n" , array[i] );
    }

    int size = sizeof(array) / sizeof(array[0]);
    printf("%s  %d" ,"Greatest->"  , sl(array , size));

    printf("\nTime Taken 20 min");
}