/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_13_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:42:39 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/04 16:21:58 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_btree.h"
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int     ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

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

void    btree_apply_prefix(t_btree  *root, void (*applyf)(void  *))
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

void    btree_apply_infix(t_btree   *root, void (*applyf)(void  *))
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


void	btree_apply_suffix(t_btree	*root, void (*applyf)(void *))
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

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
    void    *res;

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

int	btree_level_count(t_btree *root)
{
    int res;

    res = 0;
    if (!root)
        return (0);
    if (root->left)
        res = ft_max(res, btree_level_count(root->left));
    if (root->right)
        res = ft_max(res, btree_level_count(root->right));
    return (res + 1);
}

int main (void)
{
	t_btree *root = btree_create_node("1");
	root->left = btree_create_node("2");
	root->right = btree_create_node("3");
	root->left->left = btree_create_node("4");
	root->left->right = btree_create_node("5");

	btree_apply_prefix(root, (void *)&ft_putstr);
	ft_putchar('\n');
	btree_apply_infix(root, (void *)&ft_putstr);
	ft_putchar('\n');
	btree_apply_suffix(root, (void *)&ft_putstr);
	ft_putchar('\n');
	
	t_btree 	*root4;

	root4 = ((void *)0);
	btree_insert_data(&root4, "5", (void *)&ft_strcmp);
	btree_insert_data(&root4, "3", (void *)&ft_strcmp);
	btree_insert_data(&root4, "8", (void *)&ft_strcmp);
	btree_insert_data(&root4, "4", (void *)&ft_strcmp);
	btree_insert_data(&root4, "1", (void *)&ft_strcmp);
	btree_insert_data(&root4, "9", (void *)&ft_strcmp);
	btree_insert_data(&root4, "7", (void *)&ft_strcmp);
	btree_insert_data(&root4, "6", (void *)&ft_strcmp);
	btree_insert_data(&root4, "2", (void *)&ft_strcmp);
	btree_insert_data(&root4, "4", (void *)&ft_strcmp);
	btree_insert_data(&root4, "7", (void *)&ft_strcmp);

	btree_apply_infix(root4, (void *)&ft_putstr);
	ft_putchar('\n');

	char *c5;

	if ((c5 = btree_search_item(root, "4", (void *)&ft_strcmp)) != ((void *)0))
		printf("Success: string \"%s\"  found!\n\n", c5);
	else
		printf("Fail: no match found!\n\n");

	int c6;

	c6 = btree_level_count(root4);
	printf("level cnt: %d\n\n", c6);

	return (0);
}
