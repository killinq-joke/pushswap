/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:07:08 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/29 11:07:15 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortA2(t_piles *piles, int i, int median, int rrnum)
{
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
	return (rrnum);
}

void	sortA1(t_piles *piles, int i)
{
	int			median;
	int			numofinf;
	int			rrnum;

	rrnum = 0;
	median = pivotfinder(piles->pileA);
	numofinf = pileinfnum(piles->pileA, median);
	rrnum = sortA2(piles, i, median, rrnum);
	if (numofinf == 2)
		if (piles->pileB->v < piles->pileB->n->v)
			swap_b(piles, 0);
	if (pilelen(piles->pileA) == 3)
	{
		sortlow(piles);
		return ;
	}
	while (rrnum-- > 0)
		reverse_ra(piles, 0);
}
