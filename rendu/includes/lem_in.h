
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
int is_comment(char *line);
int is_start(char *line);
int is_end(char *line);
char **is_room(char *line);
void env_init(t_env *e);

#endif
