/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:01:30 by bduron            #+#    #+#             */
/*   Updated: 2017/03/16 11:30:43 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_env *e)
{
	t_list *tmp;

	tmp = e->path;
	while (tmp)
	{
		ft_printf("%s ", e->name[*(int *)(tmp->content)]);
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_env	e;
	t_graph	g;
	t_bfs	b;

	env_init(&e);
	initialize_graph(&g, FALSE);
	parse_graph(&g, &e);
	get_path(&e, &g, &b);
	move_ants(&e);
	free_all(&g, &e);
	return (0);
}
