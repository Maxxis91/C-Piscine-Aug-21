/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:56:31 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/27 23:41:28 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

#ifndef NULL
# define NULL ((VOID *)0)
#endif

int		ft_strlen(char	*str);
int		ft_nbrlen(long	nbr, int	base, int	sign);
char	*ft_print(long	nbr, char	*base, char	*res, int	sign);

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_power(int n, int p)
{
	int	res;

	res = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		res *= n;
		p--;
	}
	return (res);
}

int	ft_nbrlen(long	 nbr, int	base, int	sign)
{
	int	i;

	i = 0;
	if (sign == -1)
		i++;
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char	*ft_print(long	nbr, char	*base, char	*res, int	sign)
{
	int	i;
	int	size;

	i = 0;
	size = ft_nbrlen(nbr, ft_strlen(base), sign);
	if (sign == -1)
		res[0] = '-';
	if (nbr == 0)
	{
		res[0] = base[0];
		res[1] = '\0';
	}
	while (nbr > 0)
	{
		res[(size - i - 1)] = base[nbr % ft_strlen(base)];
		i++;
		nbr /= ft_strlen(base);
	}
	return (res);
}

char	*ft_putnbr_base(long nbr, char *base, int sign)
{
	long	nb;
	char	*res;
	int		size;
	int		len;

	nb = nbr;
	size = ft_strlen(base);
	len = ft_nbrlen(nb, size, sign);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if ((sign == -1 && len == 1) || (len == 0 && sign == 1))
	{
		res[0] = base[0];
		return (res);
	}
	return (ft_print(nb, base, res, sign));
}
