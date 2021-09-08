/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:05:16 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/03 23:10:27 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
							int (*cmpf)(void *, void *))
{
	void	*res;

	res = ((void *)0);
	if (root)
	{
		res = btree_search_item(root->left, data_ref, cmpf);
		if (!res && ((*cmpf)(root->item, data_ref) == 0))
			res = root->item;
		if (!res)
			res = btree_search_item(root->right, data_ref, cmpf);
	}
	return (res);
}
