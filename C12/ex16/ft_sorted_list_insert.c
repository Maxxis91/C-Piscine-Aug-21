/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:10:41 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 23:26:33 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_is_head(t_list	*tmp, t_list	**begin_list, t_list	*last)
{
	if (tmp == *begin_list)
	{
		*begin_list = (*begin_list)->next;
		last = *begin_list;
	}
	else
	{
		last->next = tmp->next;
		last = last->next;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*last;

	last = ((void *) 0);
	tmp = *begin_list;
	while (tmp->next)
	{
		if ((*cmp)(tmp->data, tmp->next->data) > 0)
		{
			ft_is_head(tmp, begin_list, last);
			tmp2 = tmp->next->next;
			tmp->next->next = tmp;
			tmp->next = tmp2;
			tmp = *begin_list;
		}
		else
		{
			last = tmp;
			tmp = tmp->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
		ft_list_sort(begin_list, (*cmp));
	}
}
