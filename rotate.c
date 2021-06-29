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

	if (!piles->pileA || !piles->pileA->n)
		return ;
	tmp = piles->pileA->n;
	current = piles->pileA;
	while (current->n)
		current = current->n;
	current->n = piles->pileA;
	piles->pileA = tmp;
	current->n->n = NULL;
	if (!isRR)
		addtab(piles, "ra\n");
}

void	rotate_b(t_piles *piles, int isRR)
{
	t_cell	*current;
	t_cell	*tmp;

	if (!piles->pileB || !piles->pileB->n)
		return ;
	tmp = piles->pileB->n;
	current = piles->pileB;
	while (current->n)
		current = current->n;
	current->n = piles->pileB;
	piles->pileB = tmp;
	current->n->n = NULL;
	if (!isRR)
		addtab(piles, "rb\n");
}

void	rr(t_piles *piles)
{
	rotate_a(piles, 1);
	rotate_b(piles, 1);
	addtab(piles, "rr\n");
}
