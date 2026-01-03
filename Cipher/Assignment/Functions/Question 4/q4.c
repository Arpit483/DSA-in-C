//write a function to concatenate  two strings 

#include<stdio.h>

void con_s(char str[] , char str2[])
{
    char *p = str;
    char *q = str2;
    while( *p != '\0')
    {
        p++;
    }

    while( *q != '\0')
    {
        *p = *q;
        q++;
        p++;
    }


}


int main()
{
	char name[10] = "Hello";
    char name2[10] = "Bye";
    printf("%s \n",name);
    printf("%s \n",name2);
    
    con_s(name , name2);
    
    printf(name);	
	return 0;
}