/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_shortestpath.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:01:03 by bduron            #+#    #+#             */
/*   Updated: 2017/03/07 18:02:44 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void find_path(int start, int end, int *parents)
{
	if ((start == end) || (end == -1))
		ft_printf("\n%d", start);
	else
	{
		find_path(start, parents[end], parents);
		ft_printf(" %d", end);
	}
}
