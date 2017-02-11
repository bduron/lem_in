
#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define MAXV 1000
# define NO_INPUT_ERR "Error : missing input\n"
# define NO_NODE_ERR "Error : can't find any room\n"
# define NO_ANT_ERR "Error : can't find any ant\n"
# define NO_CMD_ERR "Error : ##start or ##end is missing\n"
# define NO_PATH_ERR "Error : no valid path found\n"

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
