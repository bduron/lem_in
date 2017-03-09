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

int has_one_dash(char *line)
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

int is_circular_edge(char *roomx, char *roomy)
{
	if (ft_strcmp(roomx, roomy) == 0)
		return (1);
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
	if (len != 2 
		|| *edge[0] == '#' || *edge[0] == 'L' 
		|| !has_one_dash(line) 
		|| is_circular_edge(edge[0], edge[1])
		|| !are_existing_rooms(e, edge[0], edge[1])) 	
	{
		ft_strsplitdel(edge);
		return (NULL);
	}
	return (edge); 
}

void parse_room_to_edges(t_env *e, t_graph *g, char *line)
{
    char **edge;

    if (line == NULL) //    IF Adjacency list is empty --> Error, no edges
    {
        ft_putendl_fd(NO_EDGE_ERR, 2);
        exit(0);
    }
    if (is_comment_wrapper(line))
    	;
    else if ((edge = is_edge(e, line)))
    {
        ft_putendl_fd(line, 1);
		
    	 save_edge(e, g, edge); 
		// IF is_not_duplicate edge (check in adjacency list) / lst_find
        ft_strdel(&line);
    }
    else
        invalid_edge_err(line);
	g->nvertices = e->nroom;
}

int get_index(t_env *e, char *room_name)
{
	int i;

	i = 0;
	while (i < e->nroom && ft_strcmp(e->name[i], room_name))
		i++;
	if (i == e->nroom)
	{
		ft_putendl_fd("ERROR: get_index - room not found", 2);	
		exit(0);
	} 	
	return (i);
}

int is_in_adjacency_list(t_graph *g, int x, int y)
{
	t_edgenode *p;

	p = g->edges[x];
    while (p != NULL)
    {
        if (p->y == y)
			return (1);
       	p = p->next;
    }
	return (0);
}

void save_edge(t_env *e, t_graph *g, char **edge)
{
	int x; 
	int y;	

	x = get_index(e, edge[0]);
	y = get_index(e, edge[1]);
	if (is_in_adjacency_list(g, x, y) == FALSE)	
		insert_edge(g, x, y, FALSE); 
	ft_strsplitdel(edge);
//	else
//		ft_putendl_fd("WARNING: skipping duplicate edge", 2);	
}





















