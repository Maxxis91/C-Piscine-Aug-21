/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 22:44:33 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/27 20:50:59 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int	ft_ultimate_range(int	**range, int	min, int	max)
{
	long	i;
	int		*res;

	if (min >= max)
	{
		res = NULL;
		*range = res;
		return (0);
	}
	res = malloc(sizeof(int) * (unsigned int)(max - min));
	if (res == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	*range = res;
	return ((unsigned int)(i));
}
