#include "lem_in.h"

int main(void)
{
	t_env e;
	t_graph g;	

	env_init(&e);
	initialize_graph(&g, FALSE);
	parse_graph(&g, &e);	
	


	return (0);
}
