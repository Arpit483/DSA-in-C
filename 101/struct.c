#include <stdio.h>

struct lap 
{
    int id;
    char name[20];
    int price;
};

int main(){

    struct lap x ,y ;

   scanf("%d" , &x.id);
   scanf("%s" , &x.name);
   scanf("%d" , &y.id);
   scanf("%s" , &y.name);
   printf("%d %s" , x.id  , x.name ,  "\n");

return 0;
}