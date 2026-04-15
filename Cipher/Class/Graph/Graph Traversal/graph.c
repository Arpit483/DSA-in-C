#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* create graph */
Graph* createGraph()
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = NULL;
    g->vertexCount = 0;
    g->edgeCount = 0;
    return g;
}

/* create adjacency node */
AdjNode* createAdjNode(int v)
{
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->vertex = v;
    node->next = NULL;
    return node;
}

/* find vertex */
VertexNode* findVertex(Graph* g, int vertex)
{
    VertexNode* temp = g->vertices;

    while (temp)
    {
        if (temp->vertex == vertex)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

/* add vertex */
status_t addVertex(Graph* g, int vertex)
{
    if (findVertex(g, vertex) != NULL)
        return G_VERTEX_EXISTS;

    VertexNode* newNode = (VertexNode*)malloc(sizeof(VertexNode));
    newNode->vertex = vertex;
    newNode->adjList = NULL;
    newNode->color = WHITE;
    newNode->next = g->vertices;

    g->vertices = newNode;
    g->vertexCount++;

    return SUCCESS;
}

/* add edge */
status_t addEdge(Graph* g, int src, int dest)
{
    VertexNode* v1 = findVertex(g, src);
    VertexNode* v2 = findVertex(g, dest);

    if (!v1 || !v2)
        return G_INVALID_VERTEX;

    /* add dest to src */
    AdjNode* node = createAdjNode(dest);
    node->next = v1->adjList;
    v1->adjList = node;

    /* add src to dest (undirected) */
    node = createAdjNode(src);
    node->next = v2->adjList;
    v2->adjList = node;

    g->edgeCount++;
    return SUCCESS;
}

/* display graph */
void displayGraph(Graph* g)
{
    VertexNode* v = g->vertices;

    printf("Graph: V=%d E=%d\n", g->vertexCount, g->edgeCount);

    while (v)
    {
        printf("%d -> ", v->vertex);

        AdjNode* adj = v->adjList;
        while (adj)
        {
            printf("%d ", adj->vertex);
            adj = adj->next;
        }
        printf("\n");

        v = v->next;
    }
}

/* reset colors */
void reset(Graph* g)
{
    VertexNode* v = g->vertices;
    while (v)
    {
        v->color = WHITE;
        v = v->next;
    }
}

/* DFS */
void dfs(Graph* g)
{
    reset(g);

    VertexNode* v = g->vertices;

    printf("DFS: ");
    while (v)
    {
        if (v->color == WHITE)
            dfsVisit(g, v);
        v = v->next;
    }
    printf("\n");
}

/* DFS helper */
void dfsVisit(Graph* g, VertexNode* v)
{
    v->color = GRAY;
    printf("%d ", v->vertex);

    AdjNode* adj = v->adjList;

    while (adj)
    {
        VertexNode* next = findVertex(g, adj->vertex);
        if (next->color == WHITE)
            dfsVisit(g, next);

        adj = adj->next;
    }

    v->color = BLACK;
}

/* queue functions */
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, VertexNode* v)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->vertex = v;
    node->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = node;
        return;
    }

    q->rear->next = node;
    q->rear = node;
}

VertexNode* dequeue(Queue* q)
{
    if (q->front == NULL)
        return NULL;

    QueueNode* temp = q->front;
    VertexNode* v = temp->vertex;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return v;
}

int isEmpty(Queue* q)
{
    return q->front == NULL;
}

/* BFS */
status_t bfs(Graph* g, int start)
{
    VertexNode* s = findVertex(g, start);
    if (!s)
        return G_INVALID_VERTEX;

    reset(g);

    Queue* q = createQueue();

    s->color = GRAY;
    enqueue(q, s);

    printf("BFS: ");

    while (!isEmpty(q))
    {
        VertexNode* v = dequeue(q);
        printf("%d ", v->vertex);

        AdjNode* adj = v->adjList;

        while (adj)
        {
            VertexNode* next = findVertex(g, adj->vertex);

            if (next->color == WHITE)
            {
                next->color = GRAY;
                enqueue(q, next);
            }

            adj = adj->next;
        }

        v->color = BLACK;
    }

    printf("\n");
    return SUCCESS;
}

/* destroy graph */
void destroyGraph(Graph* g)
{
    VertexNode* v = g->vertices;

    while (v)
    {
        AdjNode* adj = v->adjList;

        while (adj)
        {
            AdjNode* temp = adj;
            adj = adj->next;
            free(temp);
        }

        VertexNode* temp = v;
        v = v->next;
        free(temp);
    }

    free(g);
}