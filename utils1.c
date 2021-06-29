/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:28:34 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/29 11:07:01 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cell	*init_cell(int value)
{
	t_cell	*new;

	new = ft_calloc(1, sizeof (t_cell));
	new->v = value;
	new->n = NULL;
	new->id = -1;
	return (new);
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

int	pilelen(t_cell *pile)
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

void	sortB1(t_piles *piles, int median, int numofsup, int i)
{
	int			rrnum;

	rrnum = 0;
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
}
