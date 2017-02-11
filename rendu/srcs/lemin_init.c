#include "lem_in.h"

void env_init(t_env *e)
{
	int i;	

	e->start = MAXV;
	e->end = MAXV;
	e->nants = 0;
	e->error = NULL;
	i = 0;
	while (i < MAXV)
	{
		e->name[i] = NULL;
		e->coor_x[i] = 0;
		e->coor_y[i] = 0;
		i++;	
	}	
}
