/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:36:06 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/10 12:17:26 by ztouzri          ###   ########.fr       */
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
		if (current->next)
		{
			ft_putnbr(current->value);
			ft_putstr(", ");
		}
		else
			ft_putnbr(current->value);
		current = current->next;
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
		if (current->next)
		{
			ft_putnbr(current->value);
			ft_putstr(", ");
		}
		else
			ft_putnbr(current->value);
		current = current->next;
	}
	ft_putstr("]\n");
}

void	print_tabs(t_piles *piles)
{
	print_pileA(piles);
	print_pileB(piles);
}
