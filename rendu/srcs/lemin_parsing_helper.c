/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:30:14 by bduron            #+#    #+#             */
/*   Updated: 2017/02/13 17:32:32 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int is_start(char *line)
{
	return (!ft_strcmp(line, START));
}

int is_end(char *line)
{
	return (!ft_strcmp(line, END));
}

int is_comment(char *line)
{
	return (line[0] == '#'
			&& (ft_strcmp(line, START) && ft_strcmp(line, END)));
}

char **is_room(char *line)
{
	char **room;
	size_t len;

	room = ft_strsplit(line, ' ');
	len = 0;
	while (room[len] != NULL)
		len++;
	if (len != 3)
	{
		ft_strsplitdel(room);
		return (NULL);
	}
	if (*room[0] == '#' || *room[0] == 'L')
	{
		ft_strsplitdel(room);
		return (NULL);
	}
	if (!ft_isdigitstr(room[1]) || !ft_isdigitstr(room[2]))
	{
		ft_strsplitdel(room);
		return (NULL);
	}
	return (room);
}

void save_room(t_env *e, char **room, t_bool *start, t_bool *end)
{
	if (is_duplicate(room[0], e))
	{
		ft_putendl_fd(DUPLICATE_ROOM_ERR, 2);
		ft_strsplitdel(room);
		exit(0);
	}
	e->name[e->nroom] = room[0]; // Strcpy ? 
	e->coor_x[e->nroom] = ft_atoi(room[1]);
	e->coor_y[e->nroom] = ft_atoi(room[2]);
	free(room); // strsplitdel ? 
	if (*start == TRUE)
	{
		e->start = e->nroom;
		*start = FALSE;
	}
	if (*end == TRUE)
	{
		e->end = e->nroom;
		*end = FALSE;
	}
	e->nroom++;
}
