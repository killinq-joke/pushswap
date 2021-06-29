/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pileutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:03:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/28 16:33:57 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cell	*pilecpy(t_cell *pile)
{
	t_cell	*cpy;
	t_cell	*currentcpy;
	t_cell	*current;

	current = pile;
	cpy = init_cell(current->v);
	currentcpy = cpy;
	while (current->n)
	{
		current = current->n;
		currentcpy->n = init_cell(current->v);
		currentcpy = currentcpy->n;
	}
	return (cpy);
}

t_cell	*groupcpy(t_cell *pile)
{
	t_cell	*cpy;
	t_cell	*currentcpy;
	t_cell	*current;
	int		groupid;

	current = pile;
	groupid = current->id;
	cpy = init_cell(current->v);
	currentcpy = cpy;
	while (current->n && current->n->id == groupid)
	{
		current = current->n;
		currentcpy->n = init_cell(current->v);
		currentcpy = currentcpy->n;
	}
	return (cpy);
}

t_cell	*pilesort(t_cell *pile)
{
	t_cell	*current;
	int		unsorted;

	unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		current = pile;
		while (current->n)
		{
			if (current->v > current->n->v)
			{
				ft_swap(&current->v, &current->n->v);
				unsorted = 1;
			}
			current = current->n;
		}
	}
	return (pile);
}

int	pivotfinder(t_cell *pile)
{
	t_cell	*sort;
	t_cell	*tmp;
	int		median;
	int		len;

	sort = pilesort(groupcpy(pile));
	tmp = sort;
	len = pilelen(sort) / 2 + pilelen(sort) % 2;
	while (len-- - 1)
		sort = sort->n;
	median = sort->v;
	free_pile(tmp);
	return (median);
}
