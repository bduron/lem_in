/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:03:50 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:05:47 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_path(void *ptr, size_t size)
{
	free(ptr);
	(void)size;
}

void	free_lemin_env(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nroom)
		ft_strdel(&e->name[i++]);
	ft_lstdel(&(e->path), del_path);
}

void	free_graph_edges(t_graph *g)
{
	t_edgenode	*tmp;
	t_edgenode	*del;
	int			i;

	i = 0;
	while (i < g->nvertices)
	{
		tmp = g->edges[i];
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		g->edges[i] = NULL;
		i++;
	}
}

void	free_graph(t_graph *g)
{
	free_graph_edges(g);
}

void	free_all(t_graph *g, t_env *e)
{
	free_lemin_env(e);
	free_graph(g);
}
