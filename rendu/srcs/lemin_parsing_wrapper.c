/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing_wrapper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:27:31 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:22:54 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_start_wrapper(char *line, t_bool *start)
{
	if (is_start(line))
	{
		*start = TRUE;
		ft_putendl_fd(line, 1);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int		is_end_wrapper(char *line, t_bool *end)
{
	if (is_end(line))
	{
		*end = TRUE;
		ft_putendl_fd(line, 1);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int		is_comment_wrapper(char *line)
{
	if (is_comment(line))
	{
		ft_putendl_fd(line, 1);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}
