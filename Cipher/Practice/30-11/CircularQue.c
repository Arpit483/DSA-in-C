# include<stdio.h>
# include<stdlib.h>

typedef struct CQ{
    int data;
    struct CQ *next;
    struct CQ *front;
    struct CQ *rear;
}cq;


cq* enque(cq *q , int i);
cq* deque(cq *q);




int main(){

    int a = 4%1;
    printf("%d" , a);
    

}





cq* enque(cq *q , int i)
{
    cq* p;
    cq *nw = (cq*)malloc(sizeof(cq));
    nw->data = i;

    if(q->next'' == NULL){
        nw ->next = nw;
        q = nw;
    }
    else
    {
        nw->next = p->next;
        p->next = nw;
    }
              
    p = nw;


}