/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:55:03 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/03 15:26:48 ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_tailA(t_piles *piles, t_cell *new)
{
	t_cell	*current;

	if (!piles->pileA)
		piles->pileA = new;
	else
	{
		current = piles->pileA;
		while (current->n)
			current = current->n;
		current->n = new;
	}
}

void	smallgroupsorterA(t_piles *piles)
{
	if (grouplen(piles->pileA) == 3)
	{
		if (pilelen(piles->pileB) == 2)
			sortlow(piles);
		sort3A(piles);
		pileidsorted(piles->pileA);
	}
	while (grouplen(piles->pileB) <= 2 && grouplen(piles->pileB) > 0)
	{
		if (grouplen(piles->pileB) == 2)
		{
			if (piles->pileB->v < piles->pileB->n->v)
				swap_b(piles, 0);
			piles->pileB->id = 0;
			push_a(piles);
			piles->pileB->id = 0;
			push_a(piles);
		}
		if (grouplen(piles->pileB) == 1)
		{
			piles->pileB->id = 0;
			push_a(piles);
		}
	}
}

int	sortA(t_piles *piles)
{
	static int	i = 1;

	while (grouplen(piles->pileA) > 3)
	{
		sortA1(piles, i);
		i++;
	}
	smallgroupsorterA(piles);
	return (0);
}

int	sortB(t_piles *piles)
{
	int			median;
	int			numofsup;
	static int	i = 1;

	while (grouplen(piles->pileB) > 3)
	{
		median = pivotfinder(piles->pileB);
		numofsup = pilesupnum(piles->pileB, median);
		sortB1(piles, median, numofsup, i);
		if (numofsup <= 2)
		{
			piles->pileA->id = 0;
			piles->pileA->n->id = 0;
			if (piles->pileA->v > piles->pileA->n->v)
				swap_a(piles, 0);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_piles	*piles;

	if (ac > 1)
	{
		piles = ft_calloc(1, sizeof (t_piles));
		if (!parser(piles, ac, av))
			return (0);
		if (!piles->pileA || !piles->pileA->n)
		{
			free_piles(piles);
			return (0);
		}
		piles->expectedpileA = pilesort(pilecpy(piles->pileA));
		piles->expectedlen = pilelen(piles->pileA);
		if (pilelen(piles->pileA) <= 3)
			sortlow(piles);
		else
			sort(piles);
		free_pile(piles->expectedpileA);
		free_res(piles->results);
		free_piles(piles);
	}
	else
		av = NULL;
	return (0);
}
