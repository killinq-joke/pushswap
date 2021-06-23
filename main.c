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
	int	median;

	median = pivotfinder(piles->pileA);
	while (pileinfisin(piles->pileA, median))
	{
		push_b(piles);
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
		if (pilelen(piles->pileA) <= 3)
		{
			sort3(piles, 'a');
		}
		else
		{
			sort(piles);
		}
		print_tabs(piles);
		free_piles(piles);
	}
	else
		av = NULL;
	return (0);
}
