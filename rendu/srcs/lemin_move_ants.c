#include "lem_in.h"

int *ft_lstinttab(t_list *alst) // to move libft
{
	int *tab;
	int len; 
	int i;
	
	if (!alst)
		return (NULL);
	len = ft_lstlen(alst);	
	tab	= malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[i++] = *(int *)(alst->content);
		alst = alst->next;	
	}
	return (tab);
}

int ft_lstlen(t_list *alst) // to move in libft
{
	int len;
	
	len = 0;
	while (alst)
	{
		len++;
		alst = alst->next;
	}
	return (len);
}

int has_reached_end(t_env *e, int *ants)
{
	int i;

	i = 0;
	while (i < e->nants)
	{
		if (ants[i++] < e->path_len)
			return (0);	
	}
	return (1);
}

void print_moves(t_env *e, int *ants, int *path_tab)
{
	int i; 

	i = 0; 
	while (i < e->nants)
	{
		if (ants[i] > 0 && ants[i] < e->path_len)
			ft_printf("L%d-%s ", i + 1, e->name[path_tab[ants[i]]]);
		i++;
	}	
	ft_printf("\n");
}

void move_ants(t_env *e)
{
	int *ants;
	int i;
	int j;
	int *path_tab;

	if (!(ants = malloc(sizeof(int) * (e->nants)))) 	
		return ;
	ft_memset(ants, 0, sizeof(int) * (e->nants));
	e->path_len = ft_lstlen(e->path);
	path_tab = ft_lstinttab(e->path);
	j = 0;
	ft_putendl("");
	while (!has_reached_end(e, ants))
	{
		i = 0;	
		while (i <= j)	
		{
			ants[i]++;		
			i++;
		}
		print_moves(e, ants, path_tab);
		if (j < e->nants)
			j++;
	}
}
