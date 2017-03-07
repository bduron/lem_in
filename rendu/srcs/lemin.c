#include "lem_in.h"

int main(void)
{
	t_env e;
	t_graph g;	

/* test linked list */
	t_list *l;

	l = ft_lstnew("word0", 6);	
	ft_lstpush(&l, ft_lstnew("word1", 6));
	ft_lstpush(&l, ft_lstnew("word2", 6));
	ft_lstpush(&l, ft_lstnew("word3", 6));
	
	while (l->next)
	{
		printf("%s -> ", (char *)(l->content));
		l = l->next;	
	}


/* test linked list */

	env_init(&e);
	initialize_graph(&g, FALSE);
	parse_graph(&g, &e);	

	ft_putendl("");
	print_graph(&g, e.name); //
	//ft_printf("index[%s] = %d\n", "room0", get_index(&e, "room0"));
	//ft_printf("index[%s] = %d\n", "room3", get_index(&e, "room3"));
	//ft_printf("index[%s] = %d\n", "room5", get_index(&e, "room5"));
	//ft_printf("index[%s] = %d\n", "room16", get_index(&e, "room16"));

	free_all(&g, &e);	


	return (0);
}
