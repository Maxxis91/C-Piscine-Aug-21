/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:28:24 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 17:15:18 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int	*ft_map(int	*tab, int	length, int(*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	if (length <= 0)
		return (NULL);
	res = (int *)malloc(sizeof(int) * length);
	if (res == 0)
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
