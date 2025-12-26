#include<stdio.h>
#include<stdlib.h>

typedef struct cd
{
    int d;
    struct cd *nx , *pv;
}cd;

cd* create(cd *n);
void dis(cd *n);

int main()
{
    cd *h = NULL;
    h = create(h);

    dis(h);

}

cd* create(cd *n)
{   int a;
    cd *q = NULL;
    do{
    
    cd *nw = (cd*)malloc(sizeof(cd));
    printf("Enter Data \n");
    scanf("%d" , &nw->d);

    if(n == NULL)
    {
          n = nw;
        n->nx = n;
        n->pv = n;
        q = n;
    }
    else
    {
       nw->nx = n;
        nw->pv = q;
        q->nx = nw;
        n->pv = nw;
        q = nw;
    }
    
    scanf("%d" , &a);
}while(a == 1);
    return n;
}

void dis(cd *n) {
    if (n == NULL) {
        printf("List is empty.\n");
        return;
    }

    cd *temp = n;

    do {
        printf("%d ", temp->d);
        temp = temp->nx;
    } while (temp != n);

    printf("\n");
}