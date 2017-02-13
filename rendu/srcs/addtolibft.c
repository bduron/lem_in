/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtolibft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:25:04 by bduron            #+#    #+#             */
/*   Updated: 2017/02/13 17:26:17 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
