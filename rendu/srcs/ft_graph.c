
#include "ft_graph.h"

void initialize_bfs(t_graph *g)
{
	int i;
	
	i = 0;
	while (i < g->nvertices)
	{
		g->bfs_processed[i] = FALSE;
		g->bfs_discovered[i] = FALSE;
		g->parent[i] = -1;
		i++;
	}
}

void bfs(t_graph *g, int start)
{
	t_list *q;
	int v;
	int y;
	t_edgenode *p;	

	
	

}


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

void print_graph(t_graph *g, char **label)
{
    int i;   
    t_edgenode *p;
	
	i = 0;
	while (i < g->nvertices)
	{
        ft_printf("[\"%7s\"] %4d | ", label[i], i);
        p = g->edges[i];
        while (p != NULL)
		{
           ft_printf("%d ", p->y);
           p = p->next;
        }
        ft_printf("\n");
		i++;
    }
}


void insert_edge(t_graph *g, int x, int y, t_bool directed)
{
	t_edgenode *p;	
	
	p = malloc(sizeof(t_edgenode));

	p->weight = 0;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x] = p;
	g->degree[x]++;
	if (directed == FALSE)
		insert_edge(g, y, x, TRUE);
	else 
		g->nedges++;
}

