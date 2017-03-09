/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:06:33 by bduron            #+#    #+#             */
/*   Updated: 2017/03/09 17:07:18 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	env_init(t_env *e)
{
	int i;

	e->start = MAXV - 1;
	e->end = MAXV - 1;
	e->nants = 0;
	e->nroom = 0;
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
