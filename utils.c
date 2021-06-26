/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/26 14:27:19 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pileinfnum(t_cell *pile, int nb)
{
	t_cell	*current;
	int		numinf;

	numinf = 0;
	current = pile;
	while (current)
	{
		if (current->v < nb)
			numinf++;
		current = current->n;
	}
	return (numinf);
}

int	pilesupnum(t_cell *pile, int nb)
{
	t_cell	*current;
	int		numsup;

	numsup = 0;
	current = pile;
	while (current)
	{
		if (current->v > nb)
			numsup++;
		current = current->n;
	}
	return (numsup);
}

int	partissorted(t_piles *piles, t_cell *pile)
{
	t_cell	*current;
	t_cell	*sort;
	int		num;

	sort = pilesort(pilecpy(pile));
	num = piles->expectedlen - pilelen(sort);
	current = piles->expectedpileA;
	while (num-- > 0)
		current = current->n;
	while (current)
	{
		if (current->v != sort->v)
			return (0);
		current = current->n;
		sort = sort->n;
	}
	return (1);
}

int	isrevsorted(t_cell *pile)
{
	t_cell	*current;

	current = pile;
	while (current->n)
	{
		if (current->v < current->n->v)
			return (0);
		current = current->n;
	}
	return (1);
}

int	pileidsorted(t_cell *pile)
{
	t_cell	*current;

	current = pile;
	while (current)
	{
		current->id = 0;
		current = current->n;
	}
	return (0);
}

int	issorted(t_piles *piles)
{
	t_cell	*current;
	t_cell	*currentsort;

	if (pilelen(piles->pileA) != pilelen(piles->expectedpileA))
		return (0);
	current = piles->pileA;
	currentsort = piles->expectedpileA;
	while (current)
	{
		if (current->v != currentsort->v)
			return (0);
		current = current->n;
		currentsort = currentsort->n;
	}
	return (1);
}
