#include<stdio.h>
#include<stdlib.h>
//Adjacency List using Directed Graph

typedef struct Node
{
    int vertex;
    struct Node* next; 
}node;


typedef struct graph
{
    int vertex;
    struct node** adjlist;
}graph;


typedef struct queue{
    int data[100];
    int front;
    int rear;
}queue;

void inqueue(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue* q)
{
    return q->front == -1;
}

void enqueue(queue* q, int value)
{
    if(q->rear == 99)
    {
        printf("Queue Full\n");
        return;
    }

    if(q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(queue* q)
{
    if(isEmpty(q))
        return -1;

    int item = q->items[q->front];

    if(q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return item;
}

node* createNode(int v)
{
    node* nw=(node*)malloc(sizeof(node));
    if(nw==NULL)
    {
        printf("\nMemory Failed Allocation");
        exit(EXIT_FAILURE);
    }
    nw->vertex=v;
    nw->next=NULL;
    return nw;
}

graph* createGraph(int vertices)
{
    graph* graph=malloc(sizeof(graph));
    if(graph==NULL)
    {
        printf("\nMemory Failed Allocation");
        exit(EXIT_FAILURE);
    }
    graph->vertex=vertices;
    graph->adjlist=(node**)malloc(vertices* sizeof(node*));
    if(graph->adjlist==NULL)
    {
        printf("\nMemoru alloc Failed");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<vertices;i++)
    {
        graph->adjlist[i]=NULL;
        
    }
    return graph;
}

void addEdg(graph* graph,int src,int dest)
{
    
    if((src>=graph->vertex || dest>=graph->vertex) || (src<0||dest<0))
    {
        printf("\nInvalid Edge");
        return;
    }
    //Add Edge from src to dest
    node* nw=createNode(dest);
    //For Undirected
    // node* new=createNode(src);
    // graph->adjlist[dest]=new;
    nw->next=graph->adjlist[src];
    nw=createNode(src);
    nw->next=graph->adjlist[dest];
    graph->adjlist[dest]=nw;
    // if(graph->adjlist[src]==NULL)
    // {
    //     graph->adjlist[src]=nw;
    // }
    // //AddEdge Destination to src
    // else
    // {
    //     node* it=graph->adjlist[src];
    //     while(it->next!=NULL)
    //     {
    //         it=it->next;
    //     }
    //     it->next=nw;
    // }

}


void BFS(graph *graph)
{
    int visited[100] = {0};
    queue q;
    inqueue(&q);
    visited[start] = 1;
    int queue[graph->vertex];

    for (int i = 0; i < graph->vertex; i++)
    {
        queue[graph->vertex];
        visited[graph->vertex];
        
        node *temp = graph->adjlist[i];
        while(temp)
        {
            queue[graph->adjlist];
            visited[graph->vertex];
            temp = temp->next;
        }
    }
}

void display(graph* graph)
{
    for(int i=0;i<graph->vertex;i++)
    {
        node* temp=graph->adjlist[i];
        printf("\nvertex: %d",i);

        while(temp)
        {
            printf(" %d-> ",temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(graph* graph)
{
    for(int i=0;i<graph->vertex;i++)
    {
        node* temp=graph->adjlist[i];
        while(temp)
        {
            node* ToDelete=temp;
            temp=temp->next;
            free(ToDelete);
        }
        free(graph->adjlist);
    }
    free(graph);
}


int main()
{
    int ver,edg,src,dest;
    printf("\nEnter number of vertices: ");
    scanf("%d",&ver);

    graph* graph=createGraph(ver);
    printf("\nEnter numbee of edges:");
    scanf("%d",&edg);

    for(int i=0;i<edg;i++)
    {
        printf("\nEnter Edge Src,Dest:");
        scanf("%d%d",&src,&dest);
        addEdg(graph,src,dest);
    }

    printf("\nAdjacency List Representation:");
    display(graph);
    freeGraph(graph);
    return 0;
}