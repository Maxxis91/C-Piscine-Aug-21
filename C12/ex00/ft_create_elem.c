/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:58:10 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 21:39:42 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void	*data)
{
	t_list	*res;

	res = ((void *) 0);
	res = (t_list *)malloc(sizeof(t_list));
	if (res == ((void *) 0))
		return ((void *) 0);
	res->data = data;
	res->next = ((void *) 0);
	return (res);
}
