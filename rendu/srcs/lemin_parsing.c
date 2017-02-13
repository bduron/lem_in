
#include "lem_in.h"

void    ft_strsplitdel(char **split) // Ajouter a la lib
{
	int i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

int ft_isdigitstr(char *s) // Ajouter a la lib
{
	if (!s)
	   return (0);
	while (*s == ' ')
		s++;
	if (*s == '-')
		s++;	
	while (*s)
		if (ft_isdigit(*s) || *s == ' ')
			s++;	
	return ((*s == '\0') ? 1 : 0);
}

char **is_room(char *line)
{
	char **room;
	size_t len;

	room = ft_strsplit(line, ' ');
	len = 0;
	while (room[len] != NULL)
		len++;	
	if (len != 3) 
	{		
		ft_strsplitdel(room);	
		return (NULL);	
	}
	if (*room[0] == '#' || *room[0] == 'L') 
	{
		ft_strsplitdel(room);	
		return (NULL);	
	}
   	if (!ft_isdigitstr(room[1]) || !ft_isdigitstr(room[2]))	
	{
		ft_strsplitdel(room);	
		return (NULL);	
	}		
	return (room);	
}

int is_start(char *line)
{
	return (!ft_strcmp(line, START));
}

int is_end(char *line)
{
	return (!ft_strcmp(line, END));
}

int is_comment(char *line)
{
	return (line[0] == '#' 
			&& (ft_strcmp(line, START) && ft_strcmp(line, END)));
}

void parse_room(t_env *e)
{
	char *line;
	char **room;
	t_bool start;
	t_bool end;

	start = FALSE; 
	end = FALSE;
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))		
	{	
		if (is_start(line))
		{	
			start = TRUE;	
			ft_putendl_fd(line, 1);	
			free(line);		
			continue ;
		}
		if (is_end(line))
		{
			end = TRUE;		
			ft_putendl_fd(line, 1);	
			free(line);		
			continue ;
		}
		if (is_comment(line))
		{ 
			ft_putendl_fd(line, 1);	
			free(line);		
			continue ;
		}
		else if ((room = is_room(line)))
		{
				ft_putendl_fd(line, 1);
				e->name[e->nroom] = room[0];
				e->coor_x[e->nroom] = ft_atoi(room[1]);
				e->coor_y[e->nroom] = ft_atoi(room[2]);
				free(room);
				e->nroom++;
				if ()	
				// save 	
		}	
		else 
		{
			ft_putendl_fd(line, 1);	
			ft_putendl_fd(INVALID_ROOM_ERR, 2);	
			free(line);		
			exit(0);
		}	
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

