/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_bfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:58:44 by bduron            #+#    #+#             */
/*   Updated: 2017/03/07 18:00:31 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)v;
	//ft_printf("processed vertex : %d\n", v);
	return ;
}

void process_edge(int v, int y)
{
	(void)v;
	(void)y;
	return ;
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
