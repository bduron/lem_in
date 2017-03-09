/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing_helper3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:18:19 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:19:10 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_duplicate(char *name, t_env *e)
{
	int i;

	i = 0;
	while (i < e->nroom)
	{
		if (ft_strcmp(name, e->name[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		are_existing_rooms(t_env *e, char *room1, char *room2)
{
	int i;

	i = 0;
	while (i < e->nroom)
	{
		if (ft_strcmp(room1, e->name[i]) == 0)
			return (1);
		if (ft_strcmp(room2, e->name[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		has_one_dash(char *line)
{
	int count;

	count = 0;
	while (*line)
	{
		if (*line == '-')
			count++;
		line++;
	}
	return (count == 1 ? 1 : 0);
}

int		is_circular_edge(char *roomx, char *roomy)
{
	if (ft_strcmp(roomx, roomy) == 0)
		return (1);
	return (0);
}
