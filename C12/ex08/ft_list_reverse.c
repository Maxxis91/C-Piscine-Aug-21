/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:30:45 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 22:36:12 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list	**begin_list)
{
	t_list	*new_start;
	t_list	*tmp;

	if ((*begin_list) && ((*begin_list)->next))
	{
		new_start = ((void *) 0);
		while (*begin_list)
		{
			tmp = (*begin_list)->next;
			(*begin_list)->next = new_start;
			new_start = *begin_list;
			*begin_list = tmp;
		}
		*begin_list = new_start;
	}
}
