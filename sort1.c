/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:14:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/29 10:52:25 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort1(t_piles *piles, int fst, int sec, int thr)
{
	if (fst > sec && fst > thr && sec > thr)
	{
		swap(piles, 'a');
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
		swap(piles, 'a');
	}
	else if (fst > sec && fst > thr && thr > sec)
	{
		swap(piles, 'a');
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
	}
}

void	sort2(t_piles *piles, int fst, int sec, int thr)
{
	if (fst > sec && fst < thr)
	{
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
		swap(piles, 'b');
	}
	else if (fst < sec && sec > thr)
		swap(piles, 'b');
	else if (fst > sec && fst > thr && thr > sec)
	{
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
	}
}

void	sort3A(t_piles *piles)
{
	int	fst;
	int	sec;
	int	thr;

	fst = piles->pileA->v;
	sec = piles->pileA->n->v;
	thr = piles->pileA->n->n->v;
	if (fst < sec && sec > thr && thr > fst)
	{
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
	}
	else if (fst > sec && fst < thr)
		swap(piles, 'a');
	else if (fst < sec && sec > thr)
	{
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
		swap(piles, 'a');
	}
	else
		sort1(piles, fst, sec, thr);
}

void	sort3B(t_piles *piles)
{
	int	fst;
	int	sec;
	int	thr;

	fst = piles->pileB->v;
	sec = piles->pileB->n->v;
	thr = piles->pileB->n->n->v;
	if (fst < sec && sec < thr)
	{
		swap(piles, 'b');
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
		swap(piles, 'b');
	}
	else if (fst < sec && sec > thr && thr > fst)
	{
		swap(piles, 'b');
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
	}
	else
		sort2(piles, fst, sec, thr);
}

int	distanceup(t_piles *piles, int median)
{
	t_cell	*current;
	int		distanceu;

	distanceu = 0;
	current = piles->pileA;
	while (current && current->v >= median)
	{
		distanceu++;
		current = current->n;
	}
	return (distanceu);
}

#include <stdio.h>
int	distancedown(t_piles *piles, int median)
{
	t_cell	*current;
	int		distanced;
	int		i;

	distanced = 0;
	current = piles->pileA;
	i = 0;
	while (current)
	{
		if (current->v < median)
			distanced = i;
		current = current->n;
		i++;
	}
	return (pilelen(piles->pileA) - distanced);
}

int	distanceinf(t_piles *piles, int median)
{
	// printf("salut %d -- %d\n", distancedown(piles, median), distanceup(piles, median));
	if (distancedown(piles, median) > distanceup(piles, median))
		return (1);
	return (0);
}
