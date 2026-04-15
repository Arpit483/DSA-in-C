#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

void test_malloc(void);
void test_calloc(void); 
void test_realloc(void); 
void* ca_calloc(size_t number_of_elements, size_t size_per_element); 

int main(void)
{
    test_malloc(); 
    test_calloc(); 
    test_realloc(); 

    return (0); 
}   

void test_malloc(void)
{
    puts("------------Entered test_malloc()-------------");
    char *ptr = (char *)malloc(16);

    if(!ptr)
    {
        puts("test_malloc(): malloc() : allocation error");
        return;
    }

    int i;
    for (i = 0; i < 16 < ++i)
    {
        usigned char n = ptr[i];
        printf("Content at index %d of the malloc \'d  character arra:: %hhu\n , i , n");
    }

    free(ptr);

    ptr = NULL;

    puts
}
