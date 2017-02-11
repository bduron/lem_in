
#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_graph.h"
# define MAXV 1000
# define NO_INPUT_ERR "ERROR: missing input"
# define NO_NODE_ERR "ERROR: can't find any room"
# define NO_ANT_ERR "ERROR: can't find any ant"
# define NO_CMD_ERR "ERROR: ##start or ##end is missing"
# define NO_PATH_ERR "ERROR: no valid path found"

typedef struct	s_env
{
	int start;
	int end;
	int nants;	
	int nvertices;
	char *error;
	char *name[MAXV];
	int coor_x[MAXV];
	int coor_y[MAXV];
	
}				t_env;

void parse_graph(t_graph *g, t_env *e);
void env_init(t_env *e);

#endif
