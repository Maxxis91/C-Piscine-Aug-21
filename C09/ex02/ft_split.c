/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:49:54 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/29 21:29:05 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	word_cnt(char	*str, char	*charset)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (is_sep(str[i + 1], charset) == 1 && is_sep(str[i], charset) == 0)
			res++;
		i++;
	}
	return (res);
}

void	put_word(char	*dest, char	*src, char	*charset)
{
	int	i;

	i = 0;
	while (is_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	put_split(char	**split, char	*str, char	*charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_sep(str[i + j], charset) == 0)
				j++;
			split[k] = (char *)malloc(sizeof(char) * (j + 1));
			put_word(split[k], str + i, charset);
			i += j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;

	words = word_cnt(str, charset);
	res = (char **)malloc(sizeof (char *) * (words + 1));
	res[words] = 0;
	put_split(res, str, charset);
	return (res);
}
