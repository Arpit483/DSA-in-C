//write a function to find the length of a string.

#include<stdio.h>
#include<string.h>

int s_len(char str[])
{
    char *p = str;
    int len = 0;

    while(*p != '\0')
    {
        p++;
        len++;
    }

    return len;
}

int main()
{
    printf("Enter the string :");
    char name[70];
    scanf("%s" , name );
	printf("Length of the String :%d" , s_len(name));
	
	return 0;
} 