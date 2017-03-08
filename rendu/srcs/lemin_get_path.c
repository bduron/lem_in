
#include "lem_in.h"

void get_path(t_env *e, t_graph *g)		
{
	initialize_bfs(g);
	bfs(g, e->start);	
	if (!(e->path = find_path_bfs(e->start, e->end, g->bfs_parent)))
		invalid_path_err();	
}
