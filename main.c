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
	new->id = -1;
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
	char	inverse;

	inverse = 'a';
	if (pilename == 'a')
	{
		pile = piles->pileA;
		inverse = 'b';
	}
	else
		pile = piles->pileB;
	if (pile->v < pile->n->v && pile->n->v > pile->n->n->v)
	{
		push(piles, inverse);
		swap(piles, pilename);
		push(piles, pilename);
	}
	else if (pile->v > pile->n->v && pile->v < pile->n->n->v)
		swap(piles, pilename);
	else if (pile->v > pile->n->v && pile->v < pile->n->v)
	{
		push(piles, inverse);
		swap(piles, pilename);
		push(piles, pilename);
		swap(piles, pilename);
	}
	else if (pile->n->v > pile->n->n->v)
	{
		swap(piles, pilename);
		push(piles, inverse);
		swap(piles, pilename);
		push(piles, pilename);
		swap(piles, pilename);
	}
	else if (pile->n->v < pile->n->n->v && pile->v > pile->n->n->v)
	{
		swap(piles, pilename);
		push(piles, inverse);
		swap(piles, pilename);
		push(piles, pilename);
	}
}

int	sort(t_piles *piles)
{
	// if (partissorted(piles, piles->pileA))
	// {
	// 	pileidsorted(piles->pileA);
	// }
	sortA(piles);
	// sortB(piles);
	// sortB(piles);
	// sortB(piles);
	return (0);
}

void	smallgroupsorterA(t_piles *piles)
{
	while (grouplen(piles->pileB) <= 2 && grouplen(piles->pileB) > 0)
	{
		if (grouplen(piles->pileB) == 2)
		{
			if (piles->pileB->v < piles->pileB->n->n->v)
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
	int	median;
	int	numofinf;
	int	rrnum;
	int	i;

	i = 1;
	while (grouplen(piles->pileA) > 3)
	{
		rrnum = 0;
		median = pivotfinder(piles->pileA);
		numofinf = pileinfnum(piles->pileA, median);
		while (pileinfnum(piles->pileA, median) > 0)
		{
			printid(piles);
			// printf("%d\n", numofinf);
			if (piles->pileA->v < median)
			{
				piles->pileA->id = i;
				push_b(piles);
			}
			else
			{
				rotate_a(piles, 0);
				rrnum++;
			}
		}
		if (numofinf == 2)
		{
			if (piles->pileB->v < piles->pileB->n->v)
				swap_b(piles, 0);
		}
		while (rrnum-- > 0)
			reverse_ra(piles, 0);
		print_pileA(piles);
		i++;
	}
	if (grouplen(piles->pileA) == 3)
	{
		sort3(piles, 'a');
		pileidsorted(piles->pileA);
	}
	smallgroupsorterA(piles);
	// if (piles->pileA->v > piles->pileA->n->v)
	// 	swap_a(piles, 0);
	// piles->pileA->id = 0;
	// piles->pileA->n->id = 0;
	return (0);
}

int	sortB(t_piles *piles)
{
	int	median;
	int	numofsup;
	int	rrnum;
	int	i;

	i = 0;
	while (grouplen(piles->pileB) > 2)
	{
		rrnum = 0;
		median = pivotfinder(piles->pileB);
		numofsup = pilesupnum(piles->pileB, median);
		// printf("salut == %d\n", median);
		while (pilesupnum(piles->pileB, median) > 0)
		{
			if (piles->pileB->v > median)
				push_a(piles);
			else
			{
				piles->pileB->id = i;
				rotate_b(piles, 0);
				rrnum++;
			}
		}
		if (numofsup <= 2)
		{
			if (piles->pileA->v > piles->pileA->n->v)
				swap_a(piles, 0);
		}
		while (rrnum--)
			reverse_rb(piles, 0);
		i++;
	}
	if (piles->pileB->v < piles->pileB->n->v)
		swap_b(piles, 0);
	if (grouplen(piles->pileB) == 2)
		push_a(piles);
	if (grouplen(piles->pileB) == 1)
		push_a(piles);
	if (partissorted(piles, piles->pileA))
	{
		pileidsorted(piles->pileA);
		// sortB(piles);
		if (isrevsorted(piles->pileB))
			pileidsorted(piles->pileB);
	}
	// piles->pileA->id = 0;
	// piles->pileA->n->id = 0;
	return (0);
}

int	sortAgroup(t_piles *piles)
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
			piles->expectedpileA = pilesort(pilecpy(piles->pileA));
			piles->expectedlen = pilelen(piles->pileA);
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
