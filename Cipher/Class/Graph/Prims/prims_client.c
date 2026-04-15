#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

#define NR_INIT_VERTICES 6
#define NR_INIT_EDGES 10 

struct edge{
	vertex_t v_start; 
	vertex_t v_end; 
	double w; 
}; 

int main(){
	graph_t *g = NULL; 
	vertex_t v; 
	vertex_t s; 
	int i; 
    ret_t ret; 

	struct edge E[] = 	{
                            {1, 2, 0.5}, {2, 3, 2.0}, {3, 4, 1.5}, {4, 5, 0.7}, {5, 6, 1.2}, 
                            {6, 1, 1.0}, {2, 6, 0.5}, {2, 5, 0.9}, {3, 5, 0.8}, {3, 6, 3.0}
						}; 

	g = create_graph(); 
	for(v = 1; v <= NR_INIT_VERTICES; ++v)
		add_vertex(g, v); 

	for(i = 0; i < NR_INIT_EDGES; ++i)
		add_edge(g, E[i].v_start, E[i].v_end, E[i].w); 

	print_graph(g, "INITIAL STATE:"); 
	
    ret = prims(g, 1);
    assert(ret); 
    print_mst(g, 1); 

	return (EXIT_SUCCESS); 
}
