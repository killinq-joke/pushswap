/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:37:24 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/29 15:37:41 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	groupwhile(t_piles *piles)
{
	while (grouplen(piles->pileB) == 3)
	{
		sort3B(piles);
		push_a(piles);
		piles->pileA->id = 0;
		push_a(piles);
		piles->pileA->id = 0;
		push_a(piles);
		piles->pileA->id = 0;
	}
	while (grouplen(piles->pileB) == 2)
	{
		if (piles->pileB->v < piles->pileB->n->v)
			swap_b(piles, 0);
		push_a(piles);
		piles->pileA->id = 0;
		push_a(piles);
		piles->pileA->id = 0;
	}
	while (grouplen(piles->pileB) == 1)
	{
		push_a(piles);
		piles->pileA->id = 0;
	}
}

void	sort3(t_piles *piles)
{
	int	fst;
	int	sec;
	int	thr;

	fst = piles->pileA->v;
	sec = piles->pileA->n->v;
	thr = piles->pileA->n->n->v;
	if (fst < sec && sec > thr && thr > fst)
	{
		swap_a(piles, 0);
		rotate_a(piles, 0);
	}
	else if (fst > sec && fst < thr)
		swap_a(piles, 0);
	else if (fst < sec && sec > thr)
		reverse_ra(piles, 0);
	else if (fst > sec && fst > thr && sec > thr)
	{
		swap_a(piles, 0);
		reverse_ra(piles, 0);
	}
	else if (fst > sec && fst > thr && thr > sec)
		rotate_a(piles, 0);
}

void	sortlow(t_piles *piles)
{
	if (piles->expectedlen == 2)
		if (piles->pileA->v > piles->pileA->n->v)
			swap(piles, 'a');
	if (pilelen(piles->pileA) == 3)
		sort3(piles);
	if (pilelen(piles->pileB) == 2)
	{
		if (piles->pileB->v < piles->pileB->n->v)
			swap_b(piles, 0);
		push_a(piles);
		push_a(piles);
	}
}

int	sort(t_piles *piles)
{
	if (!issorted(piles))
	{
		sortA(piles);
		while (!issorted(piles))
		{
			sortB(piles);
			groupwhile(piles);
		}
	}
	return (0);
}
