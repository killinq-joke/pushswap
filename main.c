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

void	sort3A(t_piles *piles)
{
	if (piles->pileA->v < piles->pileA->n->v && piles->pileA->n->v > piles->pileA->n->n->v)
	{
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
	}
	else if (piles->pileA->v > piles->pileA->n->v && piles->pileA->v < piles->pileA->n->n->v)
		swap(piles, 'a');
	else if (piles->pileA->v > piles->pileA->n->v && piles->pileA->v < piles->pileA->n->v)
	{
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
		swap(piles, 'a');
	}
	else if (piles->pileA->n->v > piles->pileA->n->n->v)
	{
		swap(piles, 'a');
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
		swap(piles, 'a');
	}
	else if (piles->pileA->n->v < piles->pileA->n->n->v && piles->pileA->v > piles->pileA->n->n->v)
	{
		swap(piles, 'a');
		push(piles, 'b');
		swap(piles, 'a');
		push(piles, 'a');
	}
}

void	sort3B(t_piles *piles)
{
	int	fst;
	int	sec;
	int	thr;

	fst = piles->pileB->v;
	sec = piles->pileB->n->v;
	thr = piles->pileB->n->n->v;
	if (fst < sec && sec < thr) // 1 2 3
	{
		swap(piles, 'b');
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
		swap(piles, 'b');
	}
	else if (fst < sec && sec > thr && thr > fst) // 1 3 2
	{
		swap(piles, 'b');
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
	}
	else if (fst > sec && fst < thr) // 2 1 3
	{
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
		swap(piles, 'b');
	}
	else if (fst < sec && sec > thr) // 2 3 1
	{
		swap(piles, 'b');
	}
	else if (fst > sec && fst > thr && thr > sec) // 3 1 2
	{
		push(piles, 'a');
		swap(piles, 'b');
		push(piles, 'b');
	}
}

int	sort(t_piles *piles)
{
	int	i;

	sortA(piles);
	i = 0;
	while (i++ < 6)
	{
		sortB(piles);
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
	}
	// while (grouplen(piles->pileB) == 3)
	// {
	// 	sort3B(piles);
	// 	push_a(piles);
	// 	piles->pileA->id = 0;
	// 	push_a(piles);
	// 	piles->pileA->id = 0;
	// 	push_a(piles);
	// 	piles->pileA->id = 0;
	// }
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

// void	smallgroupsorterB(t_piles *piles)
// {
// 	while (grouplen(piles->pileA) <= 2 && grouplen(piles->pileA) > 0)
// 	{
// 		if (grouplen(piles->pileA) == 2)
// 		{
// 			if (piles->pileA->v < piles->pileA->n->n->v)
// 				swap_a(piles, 0);
// 			piles->pileA->id = 0;
// 			push_b(piles);
// 			piles->pileA->id = 0;
// 			push_b(piles);
// 		}
// 		if (grouplen(piles->pileA) == 1)
// 		{
// 			piles->pileA->id = 0;
// 			push_b(piles);
// 		}
// 	}
// }

int	sortA(t_piles *piles)
{
	int	median;
	int	numofinf;
	int	rrnum;
	static int	i = 1;

	print_tabs(piles);
	while (grouplen(piles->pileA) > 3)
	{
		rrnum = 0;
		median = pivotfinder(piles->pileA);
		numofinf = pileinfnum(piles->pileA, median);
		while (pileinfnum(piles->pileA, median) > 0)
		{
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
		sort3A(piles);
		pileidsorted(piles->pileA);
	}
	smallgroupsorterA(piles);
	return (0);
}

int	sortB(t_piles *piles)
{
	int	median;
	int	numofsup;
	int	rrnum;
	static int	i = 1;

	while (grouplen(piles->pileB) > 3)
	{
		rrnum = 0;
		median = pivotfinder(piles->pileB);
		numofsup = pilesupnum(piles->pileB, median);
		// printf("salut == %d\n", median);
		while (pilesupnum(piles->pileB, median) > 0)
		{
			if (piles->pileB->v > median)
			{
				piles->pileB->id = i;
				push_a(piles);
			}
			else
			{
				rotate_b(piles, 0);
				rrnum++;
			}
		}
		while (rrnum--)
			reverse_rb(piles, 0);
		if (numofsup >= 3)
			sortA(piles);
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
			sort3A(piles);
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
