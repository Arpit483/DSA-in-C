//write a function to reverse the  strings 

#include<stdio.h>

void rev_s(char str[])
{
    char *p = str;

    if(*p == '\0')
        return;

    rev_s(p+1);
    printf("%c" , *p);
    
}

int main()
{
	char name[10] = "Hello";

    printf("%s \n" , name);
    rev_s(name);

	return 0;
}