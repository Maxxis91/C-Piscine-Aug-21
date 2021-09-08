/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:17:12 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/26 22:53:58 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int		ft_strlen(char	*str);
char	*ft_strcpy(char	*dest, char	*src);
char	*ft_strdup(char	*src);

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char	*src)
{
	char	*res;
	int		i;

	i = ft_strlen(src) + 1;
	res = malloc(i);
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, src);
	return (res);
}
