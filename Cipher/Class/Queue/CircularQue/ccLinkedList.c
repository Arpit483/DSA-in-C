# include <stdio.h>
# include <stdlib.h>
# include <string.h>



typedef struct CQnode{
    char name[20];
    int no;
    struct CQnode *next;

}node;

//Queue Structure

typedef struct {
    node *front;
    node *rear; 
}CQ;

void initQueue(CQ *q){
    q->front = NULL;
    q->rear = NULL;
}

node *CreateNode(int no , char name[]){
    node *nw = (node*) malloc(sizeof(node));
    if(!nw){
        printf("\n Memory Allocation Failed");
        exit(1);
    }

    nw->no = no;
    strcpy(nw->name , name );
    nw->next = NULL; 
    return nw;
}

// Insert into circular queue

void enque(CQ *q , int no , char name[]){

    node * nw = CreateNode(no , name);

    if(q->front == NULL){
        q->front = q->rear = nw;
        nw->next = nw;  // Circular
    }
    else{
        nw->next = q->front;
        q->rear->next = nw;
        q->rear = nw;
    }

    printf("Inserted:%d %s" , q->rear->no , q->rear->name);
    
}

// Delete

void deque(CQ *q ){
    if(q->front == NULL){
        printf("Queue is Empty");
        return;
    }

    node *tmp = q->front;
    
    printf("\nDeleted%d %s : " , tmp->no , tmp->name );
    if(q->front == q->rear){
        // only one node
        free(tmp);
        q->front= q->rear = NULL;
    }
    else{
        q->front = q->front->next;
        q->rear->next = q->front;
        free(tmp);
    }

}

//Display

void display(CQ *q){
    if(q->front == NULL){
        printf("Queue is Empty");
        return;
    }
    node *tmp = q->front;
    printf("\nCircular Queue Elements:\n");

    do{
        printf("[%d::%s]-->" , tmp->no , tmp->name);
        tmp = tmp->next;
    }while(tmp!=q->front);


}


int main(){

    CQ q;
    initQueue(&q);
    int ch , no;
    char name[20];

    while(1){

        printf("\n ================== CIRCULAR QUEUE : LINKED LIST ================== \n");  

        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Number and Name\n");
            scanf("%d %s" , &no , name);
            enque(&q , no , name);
            break;
        
            
        case 2:
            printf("Deque\n");
            
            deque(&q );
            break;
        
            
        case 3:
            printf("Display\n");
            display(&q);
            break;
        

            
        case 4:
            exit(0);

        default:
            printf("Invalid Choice");
            break;
        }

        


    }
}