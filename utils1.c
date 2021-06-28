/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:28:34 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/28 16:31:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
