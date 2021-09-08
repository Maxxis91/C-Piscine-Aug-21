/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:15:08 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/31 23:00:45 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_err.h"
#include <string.h>

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (res == 0)
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (!(s1[i] && s2[i]))
			break ;
		i++;
	}
	return (res);
}

void	ft_puterr(char	*basename, char	*av, char	*msg)
{
	if (!ft_strcmp(msg, strerror(21)))
		return ;
	ft_putstr(basename);
	ft_putstr(": ");
	ft_putstr(av);
	if (ft_strcmp(av, "illegal offset "))
		ft_putstr(": ");
	else
		ft_putstr("-- ");
	ft_putstr(msg);
	ft_putstr("\n");
}
