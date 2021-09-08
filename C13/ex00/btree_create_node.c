/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:51:35 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/03 00:52:24 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void	*item)
{
	t_btree	*res;

	res = ((void *) 0);
	res = (t_btree *)malloc(sizeof(t_btree));
	if (res == ((void *) 0))
		return ((void *) 0);
	res->item = item;
	res->left = ((void *) 0);
	res->right = ((void *) 0);
	return (res);
}
