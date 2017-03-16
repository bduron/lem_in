/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:49:57 by bduron            #+#    #+#             */
/*   Updated: 2017/03/16 11:53:15 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_lstinttab(t_list *alst)
{
	int *tab;
	int len;
	int i;

	if (!alst)
		return (NULL);
	len = ft_lstlen(alst);
	tab = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[i++] = *(int *)(alst->content);
		alst = alst->next;
	}
	return (tab);
}
