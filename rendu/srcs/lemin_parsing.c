/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:07:58 by bduron            #+#    #+#             */
/*   Updated: 2017/03/01 11:15:38 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void parse_edges(t_env *e, t_graph *g)
{
	char **edge;
	char *line;

	while (get_next_line(0, &line))		
	{
		if (is_comment_wrapper(line))
			continue ;
		if ((edge = is_edge(e, line)))
		{
			ft_putendl_fd(line, 1);
			save_edge(e, g, edge);
			//// IF is_not_duplicate edge (check in adjacency list) / lst_find 
			ft_strdel(&line);
		}		
		else
			invalid_edge_err(line); 
	}
}


char *parse_room(t_env *e)
{
	char *line;
	char **room;
	t_bool start;
	t_bool end;

	start = FALSE; 
	end = FALSE;
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))		
	{	
		if (is_start_wrapper(line, &start))
			continue ;
		if (is_end_wrapper(line, &end))
			continue ;
		if (is_comment_wrapper(line))
			continue ;
		else if ((room = is_room(line)))
		{
			ft_putendl_fd(line, 1);
			save_room(e, room, &start, &end);
			ft_strdel(&line);
		}	
		else 
			invalid_room_err(line);
	}
	nocmd_noroom_err(e);
	return (line);
}

void parse_ant(t_env *e)
{
	char *line;			

	if (get_next_line(0, &line) == 0)
	{
		ft_putendl_fd(NO_INPUT_ERR , 2);	
		ft_strdel(&line);		
		exit(0);
	}
	else if ((e->nants = ft_atoi(line)) < 1)
	{ 
		ft_putendl_fd(NO_ANT_ERR, 2);	
		ft_strdel(&line);		
		exit(0);
	}
	else if (e->nants > MAXANT) 
	{	
		ft_putendl_fd(MAXANT_ERR, 2);
		ft_strdel(&line);
		exit(0);
	}	
	else 
	{	
		ft_putendl_fd(line, 1);
		ft_strdel(&line);
	}	
}


void parse_graph(t_graph *g, t_env *e)
{
	char *line;

	parse_ant(e);
	line = parse_room(e);
	parse_room_to_edges(e, g, line);
	parse_edges(e, g);
	(void)g;

	//ft_printf("start = %s\nend = %s", e->name[e->start], e->name[e->end]);
}
