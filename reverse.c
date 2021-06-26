/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:37:04 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/26 16:54:08 by ztouzri          ###   ########.fr       */
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
		addtab(piles, "rra\n");
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
		addtab(piles, "rrb\n");
}

void	rrr(t_piles *piles)
{
	reverse_ra(piles, 1);
	reverse_rb(piles, 1);
	addtab(piles, "rrr\n");
}
