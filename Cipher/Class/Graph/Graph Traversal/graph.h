#pragma once

#include <stdio.h>

/* constants */
#define TRUE 1
#define FALSE 0
#define SUCCESS 1

#define G_VERTEX_EXISTS  2
#define G_INVALID_VERTEX 3
#define G_EDGE_EXISTS    4
#define G_INVALID_EDGE   5
#define QUEUE_EMPTY      6

typedef int status_t;

/* colors for traversal */
typedef enum
{
    WHITE,
    GRAY,
    BLACK
} color_t;

/* adjacency node */
typedef struct AdjNode
{
    int vertex;
    struct AdjNode* next;
} AdjNode;

/* vertex node */
typedef struct VertexNode
{
    int vertex;
    AdjNode* adjList;
    color_t color;
    struct VertexNode* next;
} VertexNode;

/* graph */
typedef struct Graph
{
    VertexNode* vertices;
    int vertexCount;
    int edgeCount;
} Graph;

/* queue node */
typedef struct QueueNode
{
    VertexNode* vertex;
    struct QueueNode* next;
} QueueNode;

/* queue */
typedef struct Queue
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

/* functions */
Graph* createGraph();
status_t addVertex(Graph* g, int vertex);
status_t addEdge(Graph* g, int src, int dest);

void displayGraph(Graph* g);

void dfs(Graph* g);
void dfsVisit(Graph* g, VertexNode* v);

status_t bfs(Graph* g, int start);

void destroyGraph(Graph* g);

/* helpers */
VertexNode* findVertex(Graph* g, int vertex);
AdjNode* createAdjNode(int v);

Queue* createQueue();
void enqueue(Queue* q, VertexNode* v);
VertexNode* dequeue(Queue* q);
int isEmpty(Queue* q);