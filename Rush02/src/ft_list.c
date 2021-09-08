/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:56:04 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/05 20:50:48 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void	*data)
{
	t_list	*res;

	res = NULL;
	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->data = data;
	res->next = (NULL);
	return (res);
}

void	ft_list_push_front(t_list	**begin_list, char	*data)
{
	t_list	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_elem(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (NULL);
}

void	ft_list_clear(t_list	*begin_list, void	(*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*list;

	list = begin_list;
	while (list)
	{
		tmp = list->next;
		if (list->data)
			free_fct(list->data);
		free(list);
		list = tmp;
	}
	begin_list = NULL;
}
