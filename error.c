/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:01:34 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/17 15:20:31 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *arg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(arg))
	{
		if (ft_isin("+-", arg[i]))
		{
			if (ft_isin("+- ", arg[i + 1]) || !arg[i + 1])
				return (1);
		}
		if (!ft_isdigit(arg[i]) && arg[i] != ' ' && \
		arg[i] != '+' && arg[i] != '-')
			return (1);
		if (arg[i + 1] && ft_isdigit(arg[i]) && \
		!ft_isin(" 0123456789", arg[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(t_piles *piles)
{
	t_cell	*current1;
	t_cell	*current2;

	current1 = piles->pileA;
	while (current1)
	{
		current2 = current1->n;
		while (current2)
		{
			if (current1->v == current2->v)
				return (1);
			current2 = current2->n;
		}
		current1 = current1->n;
	}
	return (0);
}

int	error_print(t_piles *piles, char **split)
{
	int	i;

	ft_putstr("Error\n");
	free_piles(piles);
	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
	}
	free(split);
	return (0);
}
