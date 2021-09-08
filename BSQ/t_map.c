/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:29:17 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/07 00:29:36 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"

void	t_map_constructor(t_map	*map, int	len, int	n, int	m)
{
	int	i;

	i = 0;
	t_map_props_constructor(&map->parent, len);
	map->priv = malloc(sizeof(t_map_priv));
	map->priv->elem = (char **)malloc(sizeof(char *) * n);
	while (i < n)
	{
		map->priv->elem[i] = (char *)malloc(sizeof(char) * m);
		i++;
	}
}

void	t_map_destructor(t_map	*map)
{
	int	i;

	i = 0;
	while (i < t_map_props_get_n((t_map_props *)map))
	{
		free(map->priv->elem[i]);
		i++;
	}
	t_map_props_destructor(&map->parent);
	free(map->priv->elem);
	free(map->priv);
}

t_map	*t_map_new(char	*seq, int	n, int	m)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	t_map_constructor(map, ft_strlen(seq), n, m);
	t_map_props_set_seq((t_map_props *)map, seq);
	t_map_props_set_n((t_map_props *)map, n);
	t_map_props_set_m((t_map_props *)map, m);
	return (map);
}

void	t_map_delete(t_map *map)
{
	t_map_destructor(map);
	free(map);
}
