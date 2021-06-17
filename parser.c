/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:28:41 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/08 20:17:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles(t_piles *piles)
{
	t_cell	*current;
	t_cell	*tmp;

	current = piles->pileA;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	current = piles->pileB;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(piles);
}

int	pars_ints(t_piles *piles, char **split)
{
	int		i;
	long	nb;

	i = 0;
	while (split[i])
	{
		nb = ft_atol(split[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		push_tailA(piles, init_cell(nb));
		i++;
	}
	return (1);
}

int	parser(t_piles *piles, int ac, char **av)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		if (check_error(av[i]))
			return (error_print(piles, NULL));
		split = ft_split(av[i], ' ');
		if (pars_ints(piles, split) == 0)
			return (error_print(piles, split));
		j = -1;
		while (split[++j])
			free(split[j]);
		free(split);
		if (check_dup(piles))
			return (error_print(piles, NULL));
		i++;
	}
	return (1);
}
