/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:39:13 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/04 19:32:21 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct s_tuple
{
	char	*key;
	char	*value;
}			t_tuple;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_tuple	*item;
}			t_btree;

t_tuple	*tuple_create_elem(char *key, char *value);
t_btree	*btree_create_node(t_tuple	*item);
void	btree_clear(t_btree	**root);	//вызывать с &root
void	btree_apply_prefix(t_btree	*root, void	(*applyf)(t_tuple	*));
void	btree_apply_infix(t_btree	*root, void	(*applyf)(t_tuple	*));
void	btree_apply_suffix(t_btree	*root, void	(*applyf)(t_tuple	*));
void	btree_insert_data(t_btree	**root, t_tuple	*item, \
		int	(*cmpf)(void	*, void	*));
void	*btree_search_item(t_btree	*root, void	*data_ref, \
		int	(*cmpf)(void	*, void	*));
#endif
