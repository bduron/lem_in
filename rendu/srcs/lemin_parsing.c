
#include "lem_in.h"

int is_comment(char *line)
{
	return (line[0] == '#' 
		&& (ft_strcmp(line, START) && ft_strcmp(line, END)));
}

void parse_room(t_env *e)
{
	char *line;

	(void)e;
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))		
	{	
		if (is_comment(line))
		{ 
			ft_putendl_fd(line, 2);	
		  	free(line);		
			continue ;
		}
//		if ()
//		{
//
//
//		}		

	}	
	if (!e->nroom)
	{
		ft_putendl_fd(NO_ROOM_ERR , 2);	
		exit(0);
	}
}

void parse_ant(t_env *e)
{
	char *line;			

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
	else if (e->nants > MAXANT) 
	{	
		ft_putendl_fd(MAXANT_ERR, 2);
		free(line);
		exit(0);
	}	
	else 
	{	
		ft_putendl_fd(line, 1);
		free(line);
	}	
}



void parse_graph(t_graph *g, t_env *e)
{

	parse_ant(e);
	parse_room(e);
	(void)g;

}

