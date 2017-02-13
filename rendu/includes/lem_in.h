
#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_graph.h"
# define MAXV 1000
# define MAXANT 64000
# define NO_INPUT_ERR "ERROR: missing input"
# define NO_ROOM_ERR "ERROR: can't find any room"
# define NO_ANT_ERR "ERROR: can't find any ant"
# define MAXANT_ERR "ERROR: Too many ants"
# define NO_CMD_ERR "ERROR: ##start or ##end is missing"
# define NO_PATH_ERR "ERROR: no valid path found"
# define INVALID_ROOM_ERR "ERROR: invalid room format"
# define DUPLICATE_ROOM_ERR "ERROR: duplicate room"
# define START "##start"
# define END "##end"

typedef struct	s_env
{
	int start;
	int end;
	int nants;	
	int nroom;
	char *error;
	char *name[MAXV];
	int coor_x[MAXV];
	int coor_y[MAXV];
	
}				t_env;

void parse_graph(t_graph *g, t_env *e);
void parse_ant(t_env *e);
void parse_room(t_env *e);
void nocmd_noroom_err(t_env *e);
void invalid_room_err(char *line);
int is_comment(char *line);
int is_start(char *line);
int is_start_wrapper(char *line, t_bool *start);
int is_end_wrapper(char *line, t_bool *end);
int is_comment_wrapper(char *line);
int is_end(char *line);
char **is_room(char *line);
int is_duplicate(char *name, t_env *e);
void save_room(t_env *e, char **room, t_bool *start, t_bool *end);
void env_init(t_env *e);

void    ft_strsplitdel(char **split); // add to lib
int ft_isdigitstr(char *s); // add to lib 

#endif
