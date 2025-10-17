/*
   write Program to print addresses and size of all types of pointer variables.
 
*/
#include <stdio.h>

int main()
{
    int *p;
    char *c;
    float *f;
    double *d;

    printf("Address of int pointer: %p, Size: %zu bytes\n", (void*)p, sizeof(p));
    printf("Address of char pointer: %p, Size: %zu bytes\n", (void*)c, sizeof(c));
    printf("Address of float pointer: %p, Size: %zu bytes\n", (void*)f, sizeof(f));
    printf("Address of double pointer: %p, Size: %zu bytes\n", (void*)d, sizeof(d));

    return 0;
}
