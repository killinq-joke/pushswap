/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/17 15:20:31 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pileinfisin(t_cell *pile, int nb)
{
	t_cell	*current;

	current = pile;
	while (current)
	{
		if (current->v <= nb)
			return (1);
		current = current->n;
	}
	return (0);
}
