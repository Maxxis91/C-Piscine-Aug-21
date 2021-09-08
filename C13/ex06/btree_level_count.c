/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:25:11 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/03 23:44:27 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	btree_level_count(t_btree *root)
{
	int	res;

	res = 0;
	if (!root)
		return (0);
	if (root->left)
		res = ft_max(res, btree_level_count(root->left));
	if (root->right)
		res = ft_max(res, btree_level_count(root->right));
	return (res + 1);
}
