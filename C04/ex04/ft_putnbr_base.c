/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:26 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/24 16:19:27 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char	*str);
int		ft_base_correct(char	*base);
void	ft_minint(long	a, char	*base);
void	ft_putnbr_base(int	nbr, char	*base);

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_base_correct(char	*base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_minint(long	a, char	*base)
{
	char	c;

	if (a < 0)
	{
		write(1, "-", 1);
		ft_minint(-a, base);
	}
	if (a / ft_strlen(base) == 0 && a >= 0)
	{
		c = base[a % ft_strlen(base)];
		write(1, &c, 1);
	}
	if (a / ft_strlen(base) > 0)
	{
		ft_minint(a / ft_strlen(base), base);
		ft_minint(a % ft_strlen(base), base);
	}
}

void	ft_putnbr_base(int	nbr, char	*base)
{
	char	c;

	if (ft_base_correct(base))
	{
		if (nbr == -2147483648)
			ft_minint(nbr, base);
		else
		{
			if (nbr / ft_strlen(base) == 0 && nbr >= 0)
			{
				c = base[nbr % ft_strlen(base)];
				write(1, &c, 1);
			}
			if (nbr < 0)
			{
				write(1, "-", 1);
				ft_putnbr_base(-nbr, base);
			}
			if (nbr / ft_strlen(base) > 0)
			{
				ft_putnbr_base(nbr / ft_strlen(base), base);
				ft_putnbr_base(nbr % ft_strlen(base), base);
			}
		}
	}
}
