/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:45:07 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/27 20:50:16 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int	*ft_range(int	min, int	max)
{
	int		*res;
	long	i;

	if (min >= max)
		return (NULL);
	res = (int *) malloc(sizeof (res) * (unsigned int)(max - min));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	return (res);
}
