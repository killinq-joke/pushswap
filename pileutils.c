/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pileutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:03:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/11 07:20:56 by ztouzri          ###   ########.fr       */
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
		current = current->next;
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
		pile = pile->next;
		free(tmp);
	}
}

t_cell	*pilecpy(t_cell *pile)
{
	t_cell	*cpy;
	t_cell	*currentcpy;
	t_cell	*current;

	current = pile;
	cpy = init_cell(current->value);
	currentcpy = cpy;
	while (current->next)
	{
		current = current->next;
		currentcpy->next = init_cell(current->value);
		currentcpy = currentcpy->next;
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
		while (current->next)
		{
			if (current->value > current->next->value)
			{
				ft_swap(&current->value, &current->next->value);
				unsorted = 1;
			}
			current = current->next;
		}
	}
	return (pile);
}

int		pivotfinder(t_cell *pile)
{
	t_cell	*sort;
	// t_cell	*current;
	int		median;
	int		len;

	sort = pilesort(pilecpy(pile));
	// current = sort;
	// while (current)
	// {
	// 	printf("%d, ", current->value);
	// 	current = current->next;
	// }
	len = pilelen(sort) / 2 + pilelen(sort) % 2;
	// printf("len == %d\n", len);
	while (len-- - 1)
		sort = sort->next;
	median = sort->value;
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
		current = current->next;
		i++;
	}
	group->pivotLow = current->value;
	while (i < pilelen(sort) - len)
	{
		current = current->next;
		i++;
	}
	group->pivotHigh = current->value;
}
