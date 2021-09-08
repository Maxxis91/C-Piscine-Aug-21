/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:15:29 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 21:39:14 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list	*begin_list, unsigned int	nbr)
{
	unsigned int	i;

	if (nbr == 0)
		return ((void *) 0);
	i = 1;
	while (i < nbr)
	{
		if (!begin_list)
			return ((void *) 0);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
