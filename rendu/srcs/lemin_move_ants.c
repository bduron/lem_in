/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_move_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:01:17 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:07:52 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		has_reached_end(t_env *e, int *ants)
{
	int i;

	i = 0;
	while (i < e->nants)
	{
		if (ants[i++] < e->path_len)
			return (0);
	}
	return (1);
}

void	print_moves(t_env *e, int *ants, int *path_tab)
{
	int i;

	i = 0;
	while (i < e->nants)
	{
		if (ants[i] > 0 && ants[i] < e->path_len)
			ft_printf("L%d-%s", i + 1, e->name[path_tab[ants[i]]]);
		i++;
	}
}

void	move_ants(t_env *e)
{
	int *ants;
	int i;
	int j;
	int *path_tab;

	if (!(ants = malloc(sizeof(int) * (e->nants))))
		return ;
	ft_memset(ants, 0, sizeof(int) * (e->nants));
	e->path_len = ft_lstlen(e->path);
	path_tab = ft_lstinttab(e->path);
	j = 0;
	while (!has_reached_end(e, ants))
	{
		i = 0;
		while (i < j)
			ants[i++]++;
		print_moves(e, ants, path_tab);
		if (!has_reached_end(e, ants))
			ft_printf("\n");
		if (j < e->nants)
			j++;
	}
	free(ants);
	free(path_tab);
}
