/* 

   Create a structure "Item" which includes below member variables:
   - itemName, quantity, price, amount.
   calculate the amount by accessing the member variable with the help of structure pointer.

*/

#include <stdio.h>
#include <string.h>
struct Item
{
    char itemName [100];
    int quantity;
    int price;
    int amt;
};


int main()
{
    struct Item I;
    strcpy(I.itemName , "Rice");
    I.quantity = 20;
    I.price = 200;
    I.amt = I.quantity * I.price;
    
    printf("%-15s \t %s \n%-15s \t %d \n%-15s \t %d \n%-15s \t %d \n" , "Name" , I.itemName , "Quantity" , I.quantity , "Price" ,I.price , "Amount" , I.amt );
   
   
   return 0;

}  