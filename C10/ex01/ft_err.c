/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:15:08 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/31 00:17:10 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_err.h"

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

void	ft_puterr(char	*basename, char	*av, char	*msg)
{
	ft_putstr(basename);
	ft_putstr(": ");
	ft_putstr(av);
	ft_putstr(": ");
	ft_putstr(msg);
	ft_putstr("\n");
}
