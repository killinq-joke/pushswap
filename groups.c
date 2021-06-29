/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:45:59 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/29 15:36:55 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	grouplen(t_cell *pile)
{
	t_cell	*current;
	int		groupid;
	int		len;

	len = 0;
	if (!pile)
		return (0);
	current = pile;
	groupid = current->id;
	while (current && current->id == groupid)
	{
		current = current->n;
		len++;
	}
	return (len);
}
