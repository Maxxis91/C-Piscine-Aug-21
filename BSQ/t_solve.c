/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:09:47 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 23:24:56 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_solve.h"

int	ft_min(int	a, int	b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_sub_check(char	**src, int i, int j, int size)
{
	int	k;
	int	x;
	int	y;

	k = 0;
	x = i;
	while (x < i + size)
	{
		y = j;
		while (y < j + size)
		{
			if (src[x][y] == src[i][j])
				k++;
			y++;
		}
		x++;
	}
	if (k == size * size)
		return (k);
	return (-1);
}

int	ft_solver(char	**src, char empty, int	n, int	size)
{
	int	i;
	int	j;

	i = 0;
	while (i + size < n + 1)
	{
		j = 0;
		while (j + size < ft_strlen(src[i]) + 1)
		{	
			if (ft_sub_check(src, i, j, size) >= 0)
			{
				if (src[i][j] == empty)
					return (i * n + j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

char	**ft_make_sol(t_map	*map, int	i, int	j, int	size)
{
	char	**tmp;
	char	full;
	int		len;
	int		x;
	int		y;

	len = ft_strlen(t_map_props_get_seq((t_map_props *)map));
	full = t_map_props_get_seq((t_map_props *)map)[len - 1];
	tmp = t_map_get_elem(map);
	x = i;
	while (x < i + size)
	{
		y = j;
		while (y < j + size)
		{
			tmp[x][y] = full;
			y++;
		}
		x++;
	}
	return (tmp);
}

void	ft_solve(t_map	**map)
{
	int		size;
	int		n;
	char	empty;
	int		res;
	char	**tmp;

	res = -1;
	size = ft_min(t_map_props_get_n((t_map_props *)(*map)), \
			t_map_props_get_m((t_map_props *)(*map)));
	empty = t_map_props_get_seq((t_map_props *)(*map)) \
			[ft_strlen(t_map_props_get_seq((t_map_props *)(*map))) - 3];
	n = t_map_props_get_n((t_map_props *)(*map));
	while (size > 0)
	{
		res = ft_solver(t_map_get_elem((*map)), empty, n, size);
		if (res > 0)
			break ;
		size--;
	}
	tmp = ft_make_sol((*map), res / n, res % n, size);
	t_map_set_elem((*map), tmp);
}
