/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_get_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:47:04 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 04:31:26 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"

void	t_map_set_elem(t_map	*map, char	**elem)
{
	int		i;
	char	*p;

	i = 0;
	while (i < t_map_props_get_n((t_map_props *)map))
	{
		p = map->priv->elem[i];
		map->priv->elem[i] = ft_strdup(elem[i]);
		free(p);
		i++;
	}
}

char	**t_map_get_elem(t_map	*map)
{
	return (map->priv->elem);
}
