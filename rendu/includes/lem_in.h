/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:27:55 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:33:09 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define MAXANT 2147483647
# define NO_INPUT_ERR "ERROR: missing input"
# define NO_ROOM_ERR "ERROR: can't find any room"
# define NO_ANT_ERR "ERROR: can't find any ant"
# define NO_EDGE_ERR "ERROR: can't find any edge"
# define MAXANT_ERR "ERROR: Too many ants"
# define NO_CMD_ERR "ERROR: ##start or ##end is missing"
# define NO_PATH_ERR "ERROR: no valid path found"
# define INVALID_ROOM_ERR "ERROR: invalid room format"
# define INVALID_EDGE_ERR "ERROR: invalid edge"
# define INVALID_PATH_ERR "ERROR: no path found"
# define DUPLICATE_ROOM_ERR "ERROR: duplicate room"
# define START_END_ERR "ERROR: ##start & ##end attributed to the same room"
# define START "##start"
# define END "##end"

typedef struct	s_env
{
	int		start;
	int		end;
	int		nants;
	int		nroom;
	int		path_len;
	t_list	*path;
	char	*error;
	char	*name[MAXV];
	int		coor_x[MAXV];
	int		coor_y[MAXV];

}				t_env;

void			parse_graph(t_graph *g, t_env *e);
void			parse_ant(t_env *e);
char			*parse_room(t_env *e);
void			parse_edges(t_env *e, t_graph *g);
void			parse_room_to_edges(t_env *e, t_graph *g, char *line);
void			nocmd_noroom_err(t_env *e);
int				is_comment(char *line);
int				is_start(char *line);
int				is_start_wrapper(char *line, t_bool *start);
int				is_end_wrapper(char *line, t_bool *end);
int				is_comment_wrapper(char *line);
int				is_end(char *line);
int				is_duplicate(char *name, t_env *e);
int				is_circular_edge(char *roomx, char *roomy);
int				is_in_adjacency_list(t_graph *g, int x, int y);
int				has_one_dash(char *line);
int				are_existing_rooms(t_env *e, char *room1, char *room2);
char			**is_edge(t_env *e, char *line);
char			**is_room(char *line);
void			save_room(t_env *e, char **room, t_bool *start, t_bool *end);
int				save_edge(t_env *e, t_graph *g, char **edge);
void			env_init(t_env *e);
void			invalid_room_err(char *line);
void			invalid_edge_err(char *line);
void			invalid_path_err(void);
int				get_index(t_env *e, char *room_name, int *i);
void			free_lemin_env(t_env *e);
void			free_all(t_graph *g, t_env *e);
void			get_path(t_env *e, t_graph *g, t_bfs *b);
int				has_reached_end(t_env *e, int *ants);
void			print_moves(t_env *e, int *ants, int *path_tab);
void			move_ants(t_env *e);

#endif
