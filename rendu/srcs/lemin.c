#include "lem_in.h"

int main(void)
{
	t_env e;
	t_graph g;	

	env_init(&e);
	initialize_graph(&g, FALSE);
	parse_graph(&g, &e);	

	ft_putendl("");
	print_graph(&g, e.name); 
	initialize_bfs(&g);
	bfs(&g, e.start);	
	find_path(e.start, e.end, g.bfs_parent);

	free_all(&g, &e);	


	return (0);
}
