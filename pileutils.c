/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pileutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:03:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/25 10:26:06 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pilelen(t_cell *pile)
{
	t_cell	*current;
	int		len;

	len = 0;
	current = pile;
	while (current)
	{
		current = current->n;
		len++;
	}
	return (len);
}

void	free_pile(t_cell *pile)
{
	t_cell	*tmp;

	while (pile)
	{
		tmp = pile;
		pile = pile->n;
		free(tmp);
	}
}

t_cell	*pilecpy(t_cell *pile)
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

void	printpile(t_cell *pile)
{
	t_cell	*current;

	current = pile;
	while (current)
	{
		printf("%d ,", current->v);
		current = current->n;
	}
	printf("\n");
}

int		pivotfinder(t_cell *pile)
{
	t_cell	*sort;
	int		median;
	int		len;

	sort = pilesort(pilecpy(pile));
	len = pilelen(sort) / 2 + pilelen(sort) % 2;
	printpile(pile);
	while (len-- - 1)
		sort = sort->n;
	median = sort->v;
	free_pile(sort);
	return (median);
}

void	trivotfinder(t_cell *pile, t_group_node *group)
{
	t_cell	*sort;
	t_cell	*current;
	int		len;
	int		i;

	sort = pilesort(pilecpy(pile));
	len = pilelen(sort) / 3;
	current = sort;
	i = 0;
	while (i < pilelen(sort) - (2 * len))
	{
		current = current->n;
		i++;
	}
	group->pivotLow = current->v;
	while (i < pilelen(sort) - len)
	{
		current = current->n;
		i++;
	}
	group->pivotHigh = current->v;
}
