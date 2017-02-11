
#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include "libft.h"

# define MAXV 1000

typedef struct	s_edgenode
{
	int					id;
	int					weight;
	char				*name;
	struct s_edgenode	*next;

}				t_edgenode;

typedef struct	s_graph
{
	struct s_edgenode	*edges[MAXV + 1];
	int					degree[MAXV + 1];
	int					nvertices;
	int					nedges;
	t_bool				directed;


}				t_graph;


void initialize_graph(t_graph *g, t_bool directed);

#endif
