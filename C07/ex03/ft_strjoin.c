/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 20:23:22 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/27 22:31:03 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

long	ft_res_size(int size, char **strs, char *sep)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (i < size - 1)
	{
		res += ft_strlen(strs[i]);
		res += ft_strlen(sep);
		i++;
	}
	res += (ft_strlen(strs[i]) + 1);
	return (res);
}

char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	char	*tmp;
	char	*res;
	int		i;

	if (size == 0)
	{
		res = malloc(sizeof (char));
		*res = '\0';
		return (res);
	}
	tmp = malloc(sizeof (char) * ft_res_size (size, strs, sep));
	if (tmp == NULL)
		return (NULL);
	res = tmp;
	i = 0;
	while (i < size - 1)
	{
		tmp = ft_strcpy(tmp, strs[i]);
		tmp += ft_strlen(strs[i]);
		tmp = ft_strcpy(tmp, sep);
		tmp += ft_strlen(sep);
		i++;
	}
	tmp = ft_strcpy(tmp, strs[i]);
	return (res);
}
