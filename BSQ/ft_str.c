/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:40:22 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 05:12:51 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		l;
	char	*dest;

	l = ft_strlen(src);
	dest = malloc(sizeof(char) * (l + 1));
	if (dest == NULL)
		return (NULL);
	while (l >= 0)
	{
		dest[l] = src[l];
		l--;
	}
	return (dest);
}

void	ft_append_chr(char	**str, char c)
{
	int		len;
	int		new_len;
	char	*p;

	p = *str;
	len = ft_strlen(*str);
	new_len = len + 1;
	(*str) = (char *)malloc(sizeof(char) * (new_len + 1));
	(*str)[new_len] = '\0';
	(*str)[len] = c;
	len--;
	while (len >= 0)
	{
		(*str)[len] = p[len];
		len--;
	}
	free(p);
}

char	**ft_append_str(char	**arr, char	*str, int	lines)
{
	char	**res;
	int		i;
	char	*p;

	res = (char **)malloc(sizeof(char *) * lines);
	i = 0;
	while (i < lines - 1)
	{
		p = arr[i];
		res[i] = ft_strdup(arr[i]);
		free(p);
		i++;
	}
	res[i] = ft_strdup(str);
	free(arr);
	return (res);
}
