/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_get_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:06:01 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:06:14 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_path(t_env *e, t_graph *g)
{
	initialize_bfs(g);
	bfs(g, e->start);
	if (!(e->path = find_path_bfs(e->start, e->end, g->bfs_parent)))
		invalid_path_err();
}
