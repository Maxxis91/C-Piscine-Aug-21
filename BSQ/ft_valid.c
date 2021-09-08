/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:51:55 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 23:35:45 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_valid.h"

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	check_seq(char	*seq)
{
	int	l;
	int	i;
	int	slines;

	i = 0;
	slines = 0;
	l = ft_strlen(seq);
	if (l < 4)
		return (0);
	if (seq[l - 1] == seq[l - 2] || seq[l - 1] == seq[l - 3]
		|| seq[l - 2] == seq[l - 3]
		|| (seq[l - 3] < 9 || (seq[l - 3] > 13 && seq[l - 3] < 32))
		|| (seq[l - 2] < 9 || (seq[l - 2] > 13 && seq[l - 2] < 32))
		|| (seq[l - 1] < 9 || (seq[l - 1] > 13 && seq[l - 1] < 32))
		|| seq[l - 3] == 127 || seq[l - 2] == 127 || seq[l - 1] == 127)
		return (0);
	while (i < l - 3)
	{
		if (seq[i] < 48 || seq[i] > 57)
			return (0);
		slines = slines * 10 + seq[i] - 48;
		i++;
	}
	return (slines);
}

int	is_valid(char	**tmp, int	lines)
{	
	int	i;
	int	j;
	int	slines;

	i = 1;
	if (lines < 1)
		return (0);
	slines = check_seq(tmp[0]);
	if (slines == 0 || slines != lines)
		return (0);
	while (i <= lines)
	{
		if (ft_strlen(tmp[1]) == 0 || ft_strlen(tmp[i]) != ft_strlen(tmp[1]))
			return (0);
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] != tmp[0][ft_strlen(tmp[0]) - 3]
					&& tmp[i][j] != tmp[0][ft_strlen(tmp[0]) - 2])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
