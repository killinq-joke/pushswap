/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:24:36 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/17 15:23:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *piles, int isSS)
{
	int	tmp;

	if (!piles->pileA || !piles->pileA->n)
		return ;
	tmp = piles->pileA->v;
	piles->pileA->v = piles->pileA->n->v;
	piles->pileA->n->v = tmp;
	if (!isSS)
		ft_putstr("sa\n");
}

void	swap_b(t_piles *piles, int isSS)
{
	int	tmp;

	if (!piles->pileB || !piles->pileB->n)
		return ;
	tmp = piles->pileB->v;
	piles->pileB->v = piles->pileB->n->v;
	piles->pileB->n->v = tmp;
	if (!isSS)
		ft_putstr("sb\n");
}

void	ss(t_piles *piles)
{
	swap_a(piles, 1);
	swap_b(piles, 1);
	ft_putstr("ss\n");
}

void	swap(t_piles *piles, char pilename)
{
	if (pilename == 'a')
		swap_a(piles, 0);
	else if (pilename == 'b')
		swap_b(piles, 0);
}
