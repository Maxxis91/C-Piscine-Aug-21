/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:51:35 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/04 19:42:59 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_tuple	*tuple_create_elem(char *key, char	*value)
{
	t_tuple	*res;

	res = NULL;
	res = (t_tuple *)malloc(sizeof(t_tuple));
	if (res == NULL)
		return (NULL);
	res->key = key;
	res->value = value;
	return (res);
}

t_btree	*btree_create_node(t_tuple	*item)
{
	t_btree	*res;

	res = NULL;
	res = (t_btree *)malloc(sizeof(t_btree));
	if (res == NULL)
		return (NULL);
	res->item = item;
	res->left = (NULL);
	res->right = (NULL);
	return (res);
}

void	free_tup(t_tuple *tuple)
{
	free (tuple->key);
	tuple->key = NULL;
	free (tuple->value);
	tuple->value = NULL;
	free (tuple);
}

void	node_clear(t_btree	*root, void(*free_tup)(t_tuple *tuple))
{
	if (root)
	{
		node_clear(root->left, free_tup);
		node_clear(root->right, free_tup);
		free_tup(root->item);
		root->item = NULL;
		free(root);
	}
}

void	btree_clear(t_btree	**root)
{
	node_clear(*root, free_tup);
	*root = NULL;
}
