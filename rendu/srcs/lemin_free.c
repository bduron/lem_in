
#include "lem_in.h"

void free_lemin_env(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nroom)		
		ft_strdel(&e->name[i++]);
}

void free_all(t_graph *g, t_env *e)
{
	free_lemin_env(e);

	(void)g;

}
