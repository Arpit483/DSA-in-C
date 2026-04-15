#include <stdio.h>
#include <assert.h>
#include "graph.h"

struct Edge
{
    int start;
    int end;
};

int main()
{
    Graph* g = createGraph();

    int V[] = {1, 2, 3, 4, 5, 6};
    struct Edge E[] = {
        {1,2},{1,6},{2,6},{2,5},{2,3},
        {3,4},{3,6},{3,5},{4,5},{5,6}
    };

    int i;

    /* add vertices */
    for (i = 0; i < 6; i++)
        addVertex(g, V[i]);

    /* add edges */
    for (i = 0; i < 10; i++)
        addEdge(g, E[i].start, E[i].end);

    displayGraph(g);

    dfs(g);

    bfs(g, 1);
    bfs(g, 2);
    bfs(g, 3);

    destroyGraph(g);

    return 0;
}