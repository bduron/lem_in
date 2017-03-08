#include "lem_in.h"

void print_path(t_env *e)
{
	while (e->path)
	{
		ft_printf("%s ", e->name[*(int *)(e->path->content)]);
		e->path = e->path->next;
	}
}

int main(void)
{
	t_env e;
	t_graph g;	

	env_init(&e);
	initialize_graph(&g, FALSE);
	parse_graph(&g, &e);	

//	ft_putendl("");
//	print_graph(&g, e.name); 
	get_path(&e, &g);
	move_ants(&e);

	print_path(&e);


	free_all(&g, &e);	


	return (0);
}
