/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:33:52 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/28 18:08:56 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_res(t_scell *res)
{
	t_scell	*current;
	t_scell	*tmp;

	current = res;
	while (current)
	{
		tmp = current;
		ft_putstr(current->str);
		current = current->n;
		free(tmp);
	}
}

void	free_pile(t_cell *pile)
{
	t_cell	*tmp;

	while (pile)
	{
		tmp = pile;
		pile = pile->n;
		free(tmp);
	}
}
