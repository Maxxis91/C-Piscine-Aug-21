/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:44:31 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 23:13:09 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"

long	ft_add(int	a, int	b)
{
	return ((long)(a + b));
}

long	ft_sub(int	a, int	b)
{
	return ((long)(a - b));
}

long	ft_mul(int	a, int	b)
{
	return ((long)(a * b));
}

long	ft_div(int	a, int	b)
{
	return ((long)(a / b));
}

long	ft_mod(int	a, int	b)
{
	return ((long)(a % b));
}
