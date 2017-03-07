
#include "ft_graph.h"

void initialize_bfs(t_graph *g)
{
	int i;
	
	i = 0;
	while (i < g->nvertices)
	{
		g->bfs_processed[i] = FALSE;
		g->bfs_discovered[i] = FALSE;
		g->bfs_parent[i] = -1;
		i++;
	}
}

void process_vertex_late(int v)
{
	(void)v;
	return ;
}

void process_vertex_early(int v)
{
	ft_printf("processed vertex : %d\n", v);
	return ;
}

void process_edge(int v, int y)
{
	(void)v;
	(void)y;
	return ;
}

void find_path(int start, int end, int *parents)
{
	if ((start == end) || (end == -1))
		ft_printf("\n%d", start);
	else
	{
		find_path(start, parents[end], parents);
		ft_printf(" %d", end);
	}
}

void bfs(t_graph *g, int start)
{
	t_list *queue;
	int v;
	int *pop;
	int y;
	t_edgenode *p;	

	queue = ft_lstnew(&start, sizeof(start));	
	g->bfs_discovered[start] = TRUE;
	while (queue != NULL)
	{
		pop = ft_lstpop(&queue);	
		v = *pop;
		process_vertex_early(v); //
		g->bfs_processed[v] = TRUE;
		p = g->edges[v];
		while (p != NULL)
		{
			y = p->y;
			if (g->bfs_processed[y] == FALSE)
				process_edge(v,y); //
			if (g->bfs_discovered[y] == FALSE)
			{
				ft_lstappend(&queue, ft_lstnew(&y, sizeof(int)));
				g->bfs_discovered[y] = TRUE;	
				g->bfs_parent[y] = v;	
			}		
			p = p->next;
		}
		process_vertex_late(v); //
		free(pop);
	}
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

