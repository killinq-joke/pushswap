/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:45:59 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/25 12:49:18 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	grouplen(t_cell *pile)
{
	t_cell	*current;
	int		groupid;
	int		len;

	len = 0;
	current = pile;
	groupid = current->id;
	while (current->n && current->id == groupid)
	{
		current = current->n;
		len++;
	}
	return (len);
}

// int		pivotfinder(t_cell *pile)
// {
// 	t_cell	*sort;
// 	int		median;
// 	int		len;

// 	sort = pilesort(pilecpy(pile));
// 	len = pilelen(sort) / 2 + pilelen(sort) % 2;
// 	while (len-- - 1)
// 		sort = sort->n;
// 	median = sort->v;
// 	free_pile(sort);
// 	return (median);
// }
