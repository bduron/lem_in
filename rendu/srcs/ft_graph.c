
#include "ft_graph.h"

void initialize_graph(t_graph *g, t_bool directed)
{
	int i;

	g->directed = directed;
	g->nvertices = 0;
	g->nedges = 0;

	i = 0;
	while (i < MAXV + 1)
		g->degree[i++] = 0;
	i = 0;
	while (i < MAXV + 1)
		g->edges[i++] = NULL;
}


