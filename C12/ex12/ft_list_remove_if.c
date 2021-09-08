/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:26:41 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 22:40:41 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
				int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*last;

	tmp = *begin_list;
	last = ((void *) 0);
	while (tmp)
	{
		if (cmp(tmp->data, data_ref) == 0)
		{
			if (last)
				last->next = tmp->next;
			else
				*begin_list = tmp->next;
			free_fct(tmp);
			free(tmp);
		}
		last = tmp;
		tmp = tmp->next;
	}	
}
