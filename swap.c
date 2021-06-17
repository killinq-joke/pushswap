/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:24:36 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/03 18:40:18 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *piles, int isSS)
{
	int	tmp;

	if (!piles->pileA || !piles->pileA->next)
		return ;
	tmp = piles->pileA->value;
	piles->pileA->value = piles->pileA->next->value;
	piles->pileA->next->value = tmp;
	if (!isSS)
		ft_putstr("sa\n");
}

void	swap_b(t_piles *piles, int isSS)
{
	int	tmp;

	if (!piles->pileB || !piles->pileB->next)
		return ;
	tmp = piles->pileB->value;
	piles->pileB->value = piles->pileB->next->value;
	piles->pileB->next->value = tmp;
	if (!isSS)
		ft_putstr("sb\n");
}

void	ss(t_piles *piles)
{
	swap_a(piles, 1);
	swap_b(piles, 1);
	ft_putstr("ss\n");
}
