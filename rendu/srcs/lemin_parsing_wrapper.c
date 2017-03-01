/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing_wrapper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:27:31 by bduron            #+#    #+#             */
/*   Updated: 2017/03/01 11:05:39 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void invalid_edge_err(char *line) //put in wrapper 2 
{
	ft_putendl_fd(line, 1);
	ft_putendl_fd(INVALID_EDGE_ERR, 2);
	free(line);
	exit(0);
}

void invalid_room_err(char *line)
{
	ft_putendl_fd(line, 1);
	ft_putendl_fd(INVALID_ROOM_ERR, 2);
	free(line);
	exit(0);
}

void nocmd_noroom_err(t_env *e)
{
	if (!e->nroom)
	{
		ft_putendl_fd(NO_ROOM_ERR , 2);
		exit(0);
	}
	if (e->start == MAXV - 1 || e->end == MAXV - 1)
	{
		ft_putendl_fd(NO_CMD_ERR , 2);
		exit(0);
	}
	if (e->start == e->end)
	{
		ft_putendl_fd(START_END_ERR , 2);
		exit(0);
	}
}

int is_start_wrapper(char *line, t_bool *start)
{
	if (is_start(line))
	{
		*start = TRUE;
		ft_putendl_fd(line, 1);
		free(line);
		return (1);
	}
	return (0);
}

int is_end_wrapper(char *line, t_bool *end)
{
	if (is_end(line))
	{
		*end = TRUE;
		ft_putendl_fd(line, 1);
		free(line);
		return (1);
	}
	return (0);
}


int is_comment_wrapper(char *line)
{
	if (is_comment(line))
	{
		ft_putendl_fd(line, 1);
		free(line);
		return (1);
	}
	return (0);
}

