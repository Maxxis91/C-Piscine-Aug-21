/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_12_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:01:23 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/02 23:43:26 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list	*ft_create_elem(void	*data);

#endif

t_list	*ft_create_elem(void	*data)
{
	t_list	*res;
	
	res = ((void *) 0);
	res = (t_list *)malloc(sizeof(t_list));
	if (res == ((void *) 0))
		return (((void *) 0));
	res->data = data;
	res->next = ((void *) 0);
	return (res);
}

void	ft_list_push_front(t_list	**begin_list, void	*data)
{
	t_list *tmp;
	
	if (*begin_list)
	{
		tmp = ft_create_elem(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else 
		*begin_list = ft_create_elem(data);
}

int ft_list_size(t_list *begin_list)
{
	t_list *tmp;
	int res;

	res = 0;
	tmp = begin_list;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}	
	return (res);
}

t_list	*ft_list_last(t_list	*begin_list)
{
	t_list *tmp;

	tmp = begin_list;
    while (tmp)
	{
		if (tmp->next)
    	    tmp = tmp->next;
		else
			break ;
	}
	return (tmp);
}

void    ft_list_push_back(t_list    **begin_list, void  *data)
{
    t_list  *tmp;

    if (*begin_list)
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_create_elem(data);
    }
    else
        *begin_list = ft_create_elem(data);
}

t_list	*ft_list_push_strs(int	size, char	**strs)
{
	t_list	*list;
	int		i;

	i = 0;
	while (i < size)
	{
		ft_list_push_front(&list, strs[i]);
		i++;
	}
	return (list);
}

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
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
	begin_list = ((void *) 0);
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
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

void	ft_list_reverse(t_list **begin_list)
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

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list  *list_ptr;

    list_ptr = begin_list;
    while (list_ptr)
    {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}	

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
    t_list *list_ptr;

    list_ptr = begin_list;
    while (list_ptr)
    {
        if ((*cmp)(list_ptr->data, data_ref) == 0)
            return (list_ptr);
        list_ptr = list_ptr->next;
    }
    return ((void *) 0);
}	

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

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	if (*begin_list1)
	{
		tmp = *begin_list1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}

void    ft_is_head(t_list   *tmp, t_list    **begin_list, t_list    *last)
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

void    ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *tmp;
    t_list  *tmp2;
    t_list  *last;

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

void    ft_swap_data(t_list *a, t_list  *b)
{
    t_list  tmp;

    tmp.data = a->data;
    a->data = b->data;
    b->data = tmp.data;
}

void    ft_list_reverse_fun(t_list *begin_list)
{
    t_list  *tmp;
    int     size;
    int     i;

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

void    ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list *tmp;

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, 
							 int (*cmp)())
{
	t_list *tmp;

	if (*begin_list1)
	{
		if (begin_list2)
		{
			tmp = *begin_list1;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = begin_list2;
			ft_list_sort(begin_list1, (*cmp));
		}
	}
	else if (begin_list2)
	{
		*begin_list1 = begin_list2;
	}
}

