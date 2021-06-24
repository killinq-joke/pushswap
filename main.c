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

t_cell	*init_cell(int value)
{
	t_cell	*new;

	new = ft_calloc(1, sizeof (t_cell));
	new->v= value;
	new->n= NULL;
	new->id = 1;
	return (new);
}

void	push_tailA(t_piles *piles, t_cell *new)
{
	t_cell	*current;

	if (!piles->pileA)
		piles->pileA = new;
	else
	{
		current = piles->pileA;
		while (current->n)
		{
			current = current->n;
		}
		current->n = new;
	}
}

void	sort3(t_piles *piles, char pilename)
{
	t_cell	*pile;
	if (pilename == 'a')
		pile = piles->pileA;
	else
		pile = piles->pileB;
	if (pile->v> pile->n->v&& pile->v< pile->n->n->v)
		swap(piles, pilename);
}

int	sort(t_piles *piles)
{
	sortA(piles);
	sortB(piles);
	return (0);
}

int	sortA(t_piles *piles)
{
	int	median;
	int	numofinf;

	while (pilelen(piles->pileA) > 2)
	{
		median = pivotfinder(piles->pileA);
		numofinf = pileinfnum(piles->pileA, median);
		while (pileinfnum(piles->pileA, median) > 0)
		{
			if (piles->pileA->v < median)
				push_b(piles);
			else
			{
				piles->pileA->id++;
				rotate_a(piles, 0);
			}
		}
		if (numofinf == 2)
		{
			if (piles->pileB->v < piles->pileB->n->v)
				swap_b(piles, 0);
		}
	}
	if (piles->pileA->v > piles->pileA->n->v)
		swap_a(piles, 0);
	piles->pileA->id = 0;
	piles->pileA->n->id = 0;
	return (0);
}

int	sortB(t_piles *piles)
{
	int	median;
	int	numofsup;

	while (pilelen(piles->pileB) > 2)
	{
		median = pivotfinder(piles->pileB);
		numofsup = pilesupnum(piles->pileB, median);
		while (pilesupnum(piles->pileB, median) > 0)
		{
			if (piles->pileB->v > median)
				push_a(piles);
			else
			{
				piles->pileB->id++;
				rotate_b(piles, 0);
			}
		}
		if (numofsup == 2)
		{
			if (piles->pileA->v > piles->pileA->n->v)
				swap_a(piles, 0);
		}
	}
	if (piles->pileB->v < piles->pileB->n->v)
		swap_b(piles, 0);
	if (issorted(piles->pileA))
	{
		pileidsorted(piles->pileA);
		if (isrevsorted(piles->pileB))
			pileidsorted(piles->pileB);
	}
	// piles->pileA->id = 0;
	// piles->pileA->n->id = 0;
	return (0);
}

int	printid(t_piles *piles)
{
	t_cell	*current;

	current = piles->pileA;
	printf("[");
	while (current)
	{
		printf("%d, ", current->id);
		current = current->n;
	}
	printf("] pileA \n[ ");
	current = piles->pileB;
	while (current)
	{
		printf("%d, ", current->id);
		current = current->n;
	}
	printf("] pileB \n");
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
		if (pilelen(piles->pileA) <= 3)
		{
			sort3(piles, 'a');
		}
		else
		{
			sort(piles);
			printid(piles);
		}
		print_tabs(piles);
		free_piles(piles);
	}
	else
		av = NULL;
	return (0);
}
