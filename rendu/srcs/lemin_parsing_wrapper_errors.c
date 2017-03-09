/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing_wrapper_errors.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:22:02 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:22:44 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	invalid_path_err(void)
{
	ft_putendl_fd(INVALID_PATH_ERR, 2);
	exit(0);
}

void	invalid_edge_err(char *line)
{
	ft_putendl_fd(line, 1);
	ft_putendl_fd(INVALID_EDGE_ERR, 2);
	ft_strdel(&line);
	exit(0);
}

void	invalid_room_err(char *line)
{
	ft_putendl_fd(line, 1);
	ft_putendl_fd(INVALID_ROOM_ERR, 2);
	ft_strdel(&line);
	exit(0);
}

void	nocmd_noroom_err(t_env *e)
{
	if (!e->nroom)
	{
		ft_putendl_fd(NO_ROOM_ERR, 2);
		exit(0);
	}
	if (e->start == MAXV - 1 || e->end == MAXV - 1)
	{
		ft_putendl_fd(NO_CMD_ERR, 2);
		exit(0);
	}
	if (e->start == e->end)
	{
		ft_putendl_fd(START_END_ERR, 2);
		exit(0);
	}
}
