/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:37:04 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/08 19:14:26 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ra(t_piles *piles, int isRRR)
{
	t_cell	*current;

	if (!piles->pileA || !piles->pileA->next)
		return ;
	current = piles->pileA;
	while (current->next->next)
		current = current->next;
	current->next->next = piles->pileA;
	piles->pileA = current->next;
	current->next = NULL;
	if (!isRRR)
		ft_putstr("rra\n");
}

void	reverse_rb(t_piles *piles, int isRRR)
{
	t_cell	*current;

	if (!piles->pileB || !piles->pileB->next)
		return ;
	current = piles->pileB;
	while (current->next->next)
		current = current->next;
	current->next->next = piles->pileB;
	piles->pileB = current->next;
	current->next = NULL;
	if (!isRRR)
		ft_putstr("rrb\n");
}

void	rrr(t_piles *piles)
{
	reverse_ra(piles, 1);
	reverse_rb(piles, 1);
	ft_putstr("rrr\n");
}
