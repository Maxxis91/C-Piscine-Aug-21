/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:02:00 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 23:08:41 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list	*begin_list)
{
	t_list	*tmp;
	int		res;

	res = 0;
	tmp = begin_list;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

void	ft_swap_data(t_list	*a, t_list	*b)
{
	t_list	tmp;

	tmp.data = a->data;
	a->data = b->data;
	b->data = tmp.data;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	int		size;
	int		i;

	if (begin_list || begin_list->next)
	{
		size = ft_list_size(begin_list);
		while (size)
		{
			i = 0;
			tmp = begin_list;
			while (i < (size - 1))
			{
				ft_swap_data(tmp, tmp->next);
				tmp = tmp->next;
				i++;
			}
			size--;
		}
	}
}
