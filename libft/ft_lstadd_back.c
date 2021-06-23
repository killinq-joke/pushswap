/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:32:21 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/17 15:20:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	current = *alst;
	if (!(new))
		return ;
	if (!(alst) || !(*alst))
	{
		*alst = new;
		return ;
	}
	while (current->n)
		current = current->n;
	current->n = new;
}
