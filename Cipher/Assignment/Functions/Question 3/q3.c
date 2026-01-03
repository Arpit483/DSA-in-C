//Write a separate function to copy one string into another string 

#include<stdio.h>


void c_string(char str[] , char str2[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        str2[i] = str[i];
        i++;
    }

}


int main()
{
    char name[10] = "Hello";
    char name2[10] = "Bye";

    c_string(name , name2);
    printf("%s \n" , name);
    printf("%s" , name2);
	
	
	return 0;
}