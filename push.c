/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:35:57 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/03 15:37:00 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_piles *piles)
{
	t_cell	*tmp;

	if (!piles->pileB)
		return ;
	tmp = piles->pileB->next;
	piles->pileB->next = piles->pileA;
	piles->pileA = piles->pileB;
	piles->pileB = tmp;
	ft_putstr("pa\n");
}

void	push_b(t_piles *piles)
{
	t_cell	*tmp;

	if (!piles->pileA)
		return ;
	tmp = piles->pileA->next;
	piles->pileA->next = piles->pileB;
	piles->pileB = piles->pileA;
	piles->pileA = tmp;
	ft_putstr("pb\n");
}
