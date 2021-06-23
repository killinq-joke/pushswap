/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:37:04 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/17 15:20:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ra(t_piles *piles, int isRRR)
{
	t_cell	*current;

	if (!piles->pileA || !piles->pileA->n)
		return ;
	current = piles->pileA;
	while (current->n->n)
		current = current->n;
	current->n->n = piles->pileA;
	piles->pileA = current->n;
	current->n = NULL;
	if (!isRRR)
		ft_putstr("rra\n");
}

void	reverse_rb(t_piles *piles, int isRRR)
{
	t_cell	*current;

	if (!piles->pileB || !piles->pileB->n)
		return ;
	current = piles->pileB;
	while (current->n->n)
		current = current->n;
	current->n->n = piles->pileB;
	piles->pileB = current->n;
	current->n = NULL;
	if (!isRRR)
		ft_putstr("rrb\n");
}

void	rrr(t_piles *piles)
{
	reverse_ra(piles, 1);
	reverse_rb(piles, 1);
	ft_putstr("rrr\n");
}
