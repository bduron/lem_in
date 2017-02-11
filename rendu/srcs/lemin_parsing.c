
#include "lem_in.h"






void parse_graph(t_graph *g, t_env *e)
{
	char *line;			

	(void)g;

	if (get_next_line(0, &line) == 0)
	{
		ft_putendl_fd(NO_INPUT_ERR , 2);	
		free(line);		
		exit(0);
	}
	else if ((e->nants = ft_atoi(line)) < 1)
	{ 
		ft_putendl_fd(NO_ANT_ERR, 2);	
		free(line);		
		exit(0);
	}
	else 
	{	
		ft_putendl_fd(line, 1);
		free(line);
	}


	while (get_next_line(0, &line))
	{
		ft_putendl_fd(line, 1);	
		free(line);		
	}
}

