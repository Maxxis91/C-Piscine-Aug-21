/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:34:56 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/04 19:15:17 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree	*root, void	(*applyf)(t_tuple	*))
{
	if (root)
	{
		(*applyf)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
	else
		return ;
}

void	btree_apply_infix(t_btree	*root, void	(*applyf)(t_tuple	*))
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf);
		(*applyf)(root->item);
		if (root->right)
			btree_apply_infix(root->right, applyf);
	}
	else
		return ;
}

void	btree_apply_suffix(t_btree	*root, void	(*applyf)(t_tuple	*))
{
	if (root)
	{
		if (root->left)
			btree_apply_suffix(root->left, applyf);
		if (root->right)
			btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
	else
		return ;
}

void	btree_insert_data(t_btree	**root, t_tuple	*item, \
		int	(*cmpf)(void	*, void	*))
{
	if (!(*root))
		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

void	*btree_search_item(t_btree	*root, void	*data_ref, \
		int	(*cmpf)(void	*, void	*))
{
	void	*res;

	res = NULL;
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
