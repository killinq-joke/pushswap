/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:44:24 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/03 17:34:53by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_piles *piles, int isRR)
{
	t_cell	*current;
	t_cell	*tmp;

	if (!piles->pileA || !piles->pileA->next)
		return ;
	tmp = piles->pileA->next;
	current = piles->pileA;
	while (current->next)
		current = current->next;
	current->next = piles->pileA;
	piles->pileA = tmp;
	current->next->next = NULL;
	if (!isRR)
		ft_putstr("ra\n");
}

void	rotate_b(t_piles *piles, int isRR)
{
	t_cell	*current;
	t_cell	*tmp;

	if (!piles->pileB || !piles->pileB->next)
		return ;
	tmp = piles->pileB->next;
	current = piles->pileB;
	while (current->next)
		current = current->next;
	current->next = piles->pileB;
	piles->pileB = tmp;
	current->next->next = NULL;
	if (!isRR)
		ft_putstr("rb\n");
}

void	rr(t_piles *piles)
{
	rotate_a(piles, 1);
	rotate_b(piles, 1);
	ft_putstr("rr\n");
}
