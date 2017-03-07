
#include "libft.h"

int main(void)
{
	t_list *l;
	char *pop;

	l = ft_lstnew("word0", 6);	
	//ft_lstappend(&l, ft_lstnew("word1", 6));
	//ft_lstappend(&l, ft_lstnew("word2", 6));
	//ft_lstappend(&l, ft_lstnew("word3", 6));
	//ft_lstappend(&l, ft_lstnew("word4", 6));
	//pop = ft_lstpop(&l);
	pop = ft_lstpop(&l);
	
	
	//while (l)
	//{
	//	ft_printf("%s ", (char *)(l->content));
	//	l = l->next;	
	//}

	ft_printf("\npop = %s\n", pop);
	if (l == NULL)
		ft_printf("*l = NULL\n");

	return (0);
}
