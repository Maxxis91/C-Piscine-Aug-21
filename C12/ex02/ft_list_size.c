/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:52:08 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 20:57:36 by gmelissi         ###   ########.fr       */
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
