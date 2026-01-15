#include <stdio.h>
#include<stdlib.h>

typedef struct queLL
{
    int data;
    struct queLL *next;
    struct queLL *front;
    struct queLL *rear;
}qll;

qll* push(qll* front , int data)
{
    qll* nw = (qll*)malloc(sizeof(qll));
    nw->data = data;
    nw->next = top;


}