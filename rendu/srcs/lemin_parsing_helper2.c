/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parsing_helper2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:32:52 by bduron            #+#    #+#             */
/*   Updated: 2017/03/01 11:17:45 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int is_duplicate(char *name, t_env *e)
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

int are_existing_rooms(t_env *e, char *room1, char *room2)
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

char **is_edge(t_env *e, char *line)
{
	char **edge;	
	size_t len;
		
	edge = ft_strsplit(line, '-');
	len = 0;
	while (edge[len] != NULL)
		len++;	
	if (len != 2 || *edge[0] == '#' || *edge[0] == 'L') 	
	{
		ft_strsplitdel(edge);
		return (NULL);
	}
	if (!are_existing_rooms(e, edge[0], edge[1]))
	{
		ft_strsplitdel(edge);
		return (NULL);
	}	
	return (edge); 
}

void parse_edges_transition(t_env *e, t_graph *g, char *line)
{
    char **edge;
    size_t nlines_read;

    parse_edge_transition(e, g, line);
    nlines_read = 0;
    while (get_next_line(0, &line))
    {
        if (is_comment_wrapper(line))
            continue ;
        if ((edge = is_edge(e, line)))
        {
            ft_putendl_fd(line, 1);
    //      save_edge(e, g, edge); // [ ] // IF is_not_duplicate edge (check in adjacency list) / lst_find
            free(line);
        }
        else
            invalid_edge_err(line);
        nlines_read++;
    }
    if (!nlines_read) //    IF Adjacency list is empty --> Error, no edges
    {
        ft_putendl_fd(NO_EDGE_ERR, 2);
        exit(0);
    }
    (void)g; //////
}






















