/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:55:12 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/22 20:57:50 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	slen(char	*str);

unsigned int	slen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int	size);

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int	size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	sz_d;
	unsigned int	sz_s;

	i = slen(dest);
	j = 0;
	sz_d = slen(dest);
	sz_s = slen(src);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size == 0 || size < sz_d)
		return (sz_s + size);
	else
		return (sz_d + sz_s);
}
