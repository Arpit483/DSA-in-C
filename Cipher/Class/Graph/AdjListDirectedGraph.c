#include<stdio.h>
#include<stdlib.h>


typedef struct LL
{
    int data;
    struct LL *next;
} t;

struct grp
{
    int ver;
    t *node;
}

void create()
{
    int ver;
    printf("Enter Number of Vertices: ");
    scanf("%d", &ver);

    for (int i = 0; i < ver; i++)
    {

    }

}