/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:41:23 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 23:11:16 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

int	ft_isspace(char	c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(char	*str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= 48 && *str <= 57))
	{
		res = res * 10 + *str - 48;
		str++;
	}
	res *= sign;
	return (res);
}

void	ft_putnbr(int	nb)
{
	char	c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb >= 0 && nb <= 9)
		{
			c = nb + '0';
			write(1, &c, 1);
		}
		if (nb < 0)
		{
			write (1, "-", 1);
			ft_putnbr(-nb);
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}
