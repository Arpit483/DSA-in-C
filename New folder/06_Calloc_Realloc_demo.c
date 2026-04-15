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
    puts("------------------------Entered test_malloc()------------------------"); 
    char* ptr = (char*)malloc(16); 
    if(!ptr)
    {
        puts("test_malloc():malloc():allocation error"); 
        return; 
    }

    int i; 
    for(i = 0; i < 16; ++i)
    {
        unsigned char n = ptr[i]; 
        printf("Content at index %d of the malloc\'d character array : %hhu\n", i, n); 
    }

    free(ptr); 
    ptr = NULL; 

    puts("We have seen that memory block allocated by malloc() contains garbage values"); 
    puts("We can make use of memset() to zero out the content"); 

    ptr = (char*)malloc(16); 
    if(!ptr)
    {
        puts("test_malloc():malloc():allocation error"); 
        return; 
    }
    //  Initialize malloc'd block to zero 
    memset(ptr, 0, 16); 

    puts("Printing initalized memory block"); 
    for(i = 0; i < 16; ++i)
    {
        unsigned char n = ptr[i]; 
        printf("Content at index %d of the malloc\'d character array : %hhu\n", i, n); 
    }

    free(ptr); 
    ptr = NULL; 

    puts("------------------------Leaving test_malloc()------------------------"); 
}

void test_calloc(void)
{
    puts("------------------------Entered test_calloc()------------------------"); 

    int* p = (int*)calloc(1, sizeof(int)); 
    if(!p)
    {
        puts("test_calloc():calloc():allocation error"); 
        return; 
    }

    printf("*p = %d\n", *p);    //  Guaranteed to be zero 
    free(p); 
    p = NULL; 

    struct Date* pDate = (struct Date*)calloc(1, sizeof(struct Date)); 
    if(!pDate)
    {
        puts("test_calloc():calloc():allocation error"); 
        return;     
    }

    //  Guaranteed to be zero 
    printf("pDate->day = %d, pDate->month = %d, pDate->year = %d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL; 

    puts("------------------------Leaving test_calloc()------------------------"); 
}

void test_realloc(void)
{
    puts("------------------------Entered test_realloc()------------------------"); 
    puts("------------------------Leaving test_realloc()------------------------"); 
}

void* ca_calloc(size_t number_of_elements, size_t size_per_element)
{
    puts("In cpa_calloc()"); 
    size_t size_in_bytes = number_of_elements * size_per_element; 
    void* ptr = malloc(size_in_bytes); 
    
    if(ptr)
        memset(ptr, 0, size_in_bytes); 
    
    return (ptr); 
}

//  void* realloc(void* old_ptr, size_t new_size); 

//  realloc(NULL, 16); == malloc(16);