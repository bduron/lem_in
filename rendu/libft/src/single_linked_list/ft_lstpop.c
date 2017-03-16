/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:54:48 by bduron            #+#    #+#             */
/*   Updated: 2017/03/16 11:58:35 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **alst)
{
	void	*data;
	t_list	*tmp;

	if (!*alst)
		return (NULL);
	data = (*alst)->content;
	tmp = *alst;
	*alst = (*alst)->next;
	free(tmp);
	return (data);
}
