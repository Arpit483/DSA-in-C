#include<stdio.h>
#include<stdlib.h>
#define MAX 30

int adj[MAX][MAX];
int ver;

void create()
{
    int edg, src, dest;
    printf("Enter Number of vertices: \n");
    scanf("%d", &ver);
    if(ver > MAX)
    {
        printf("Vertices Exceeds Limits\n");
        return;
    }

    printf("Enter Number of Edges \n");
    scanf("%d", &edg);

    // Initialize the matrix 
    for(int i = 0; i < ver ; i++)
    {
        for(int j = 0; j < ver ; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Enter Age
    for (int i = 0; i < edg; i++)
    {
        printf("Enter Source and Destination: ");
        scanf("%d %d", &src, &dest);

        if(src >= ver || src < 0 || dest >= ver || dest < 0)
        {
            printf("Invalid Edge\n");
            i--;
            continue;
        }

        adj[src][dest] = 1;
        adj[dest][src] = 1; // Remove for directed graph
    }
}

void display()
{
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            printf("%d \t", adj[i][j]);
        }
    }
}


int main()
{
    create();
    display();
    return 0;
}




