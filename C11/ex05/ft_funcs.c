/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:46:36 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 23:07:32 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_funcs.h"
#include "ft_ops.h"

void	ft_arr_func(t_func *ops)
{
	ops[0] = &ft_add;
	ops[1] = &ft_sub;
	ops[2] = &ft_mul;
	ops[3] = &ft_div;
	ops[4] = &ft_mod;
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (res == 0)
	{
		res = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (res);
}

int	is_op(char *str)
{
	if (ft_strcmp(str, "+") == 0)
		return (0);
	if (ft_strcmp(str, "-") == 0)
		return (1);
	if (ft_strcmp(str, "*") == 0)
		return (2);
	if (ft_strcmp(str, "/") == 0)
		return (3);
	if (ft_strcmp(str, "%") == 0)
		return (4);
	return (-1);
}
