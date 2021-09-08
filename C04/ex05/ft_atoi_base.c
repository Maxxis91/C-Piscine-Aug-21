/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:02:22 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/24 19:10:05 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char	c);
int	ft_atoi_base_correct(char	*base);
int	ft_in_base(char	c, char	*base);
int	ft_atoi_base(char	*str, char	*base);

int	ft_isspace(char	c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi_base_correct(char	*base)
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
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
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

int	ft_in_base(char	c, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char	*str, char	*base)
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
	while (*str && ft_in_base(*str, base) >= 0)
	{
		res = res * ft_strlen(base) + ft_in_base(*str, base);
		str++;
	}
	res *= sign;
	return (res);
}
