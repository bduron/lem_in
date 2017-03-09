
#include "lem_in.h"

void del_path(void *ptr, size_t size)
{
	free(ptr);
	(void)size;
}


void free_lemin_env(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nroom)		
		ft_strdel(&e->name[i++]);
	ft_lstdel(&(e->path), del_path); 

}


void free_graph_edges(t_graph *g)
{
	t_edgenode *tmp;
	t_edgenode *del;
	int i;		

	i = 0;
//	ft_printf("\nnedges = %d\n", g->nvertices);
	while (i < g->nvertices)
	{
		tmp = g->edges[i];
//		ft_printf("\nNode[%d]\n", i);//					
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
//			ft_printf("removing %d\n", del->y); //					
			free(del);	
		}		
		g->edges[i] = NULL;
		i++;
	}
}

void free_graph(t_graph *g)
{
	free_graph_edges(g);

}


void free_all(t_graph *g, t_env *e)
{
	free_lemin_env(e);
	free_graph(g);

	(void)g;

}
