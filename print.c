/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:36:06 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/17 15:20:31 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pileA(t_piles *piles)
{
	t_cell	*current;

	current = piles->pileA;
	ft_putstr("[");
	while (current)
	{
		if (current->n)
		{
			ft_putnbr(current->v);
			ft_putstr(", ");
		}
		else
			ft_putnbr(current->v);
		current = current->n;
	}
	ft_putstr("]\n");
}

void	print_pileB(t_piles *piles)
{
	t_cell	*current;

	current = piles->pileB;
	ft_putstr("[");
	while (current)
	{
		if (current->n)
		{
			ft_putnbr(current->v);
			ft_putstr(", ");
		}
		else
			ft_putnbr(current->v);
		current = current->n;
	}
	ft_putstr("]\n");
}

void	print_tabs(t_piles *piles)
{
	print_pileA(piles);
	print_pileB(piles);
}
