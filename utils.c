/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:49 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/24 14:56:48 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pileinfnum(t_cell *pile, int nb)
{
	t_cell	*current;
	int		numinf;
	int		groupid;

	numinf = 0;
	current = pile;
	groupid = current->id;
	while (current && current->id == groupid)
	{
		if (current->v < nb)
			numinf++;
		current = current->n;
	}
	return (numinf);
}

int	pilesupnum(t_cell *pile, int nb)
{
	t_cell	*current;
	int		numsup;
	int		groupid;

	numsup = 0;
	current = pile;
	groupid = current->id;
	while (current && current->id == groupid)
	{
		if (current->v > nb)
			numsup++;
		current = current->n;
	}
	return (numsup);
}

int	issorted(t_cell *pile)
{
	t_cell	*current;

	current = pile;
	while (current->n)
	{
		if (current->v > current->n->v)
			return (0);
		current = current->n;
	}
	return (1);
}

int	isrevsorted(t_cell *pile)
{
	t_cell	*current;

	current = pile;
	while (current->n)
	{
		if (current->v < current->n->v)
			return (0);
		current = current->n;
	}
	return (1);
}

int	pileidsorted(t_cell *pile)
{
	t_cell	*current;

	current = pile;
	while (current)
	{
		current->id = 0;
		current = current->n;
	}
	return (0);
}
