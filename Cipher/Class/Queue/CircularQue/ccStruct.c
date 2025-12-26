# include <stdio.h>
# include <stdlib.h>

#define MAX 5

typedef struct {
    
    int arr[MAX];
    int front;
    int rear;

}CQ;

// Initial Queue 

void initialize (CQ *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(CQ *q){
 
    return (((q->rear+1) %MAX )== (q->front)) ;
}

int isEmpty(CQ *q){
 
    return (q->front == -1);
}

// Enque

void enque(CQ *q , int data){
 
    if(isFull(q)){
        printf("Queue is Full.\n");
        return;
    }

    if(q->front == -1){
        // First Time Insertion
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX ;
    q->arr[q->rear] = data;

    printf( "Inserted:%d\n" , q->arr[q->rear]);

}


int deque(CQ *q){
    
    if(isEmpty(q)){
        return -1;
    }

    int data = q->arr[q->front];

    if(q->front == q->rear){
        // Queue becomes empty
        q->front = q->rear = -1;
    }
    else{
        q->front = q->front+1 % MAX;
    }

    return data;

}

//display

void display(CQ *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements\n");
    int i = q->front;

    while(1){
        printf("%d\t" , q->arr[i]);
        if(i==q->rear)
            break;

        i = (i+1) % MAX;
    }
    printf("\n");

}


int main(){
    CQ q ; 
   initialize(&q);

    enque(&q , 10);
    enque(&q , 20);
    enque(&q , 30);
    display(&q);

    printf("Removed:%d\n" ,deque(&q) );
    printf("Removed:%d\n" ,deque(&q) );



    enque(&q , 40);
    enque(&q , 50);
    enque(&q , 60);  // Wrap around

    display(&q);
    
}