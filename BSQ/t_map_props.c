/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_props.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:39:35 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/07 00:03:14 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map_props.h"

void	t_map_props_constructor(t_map_props	*map_props, int	len)
{
	map_props->priv = malloc(sizeof(t_map_props_priv));
	map_props->priv->seq = malloc(sizeof(char) * len);
	map_props->priv->n = 0;
	map_props->priv->m = 0;
}

void	t_map_props_destructor(t_map_props	*map_props)
{
	free(map_props->priv->seq);
	free(map_props->priv);
}

t_map_props	*t_map_props_new(int	len)
{
	t_map_props	*map_props;

	map_props = (t_map_props *)malloc(sizeof(t_map_props));
	t_map_props_constructor(map_props, len);
	return (map_props);
}

void	t_map_props_delete(t_map_props	*map_props)
{
	t_map_props_destructor(map_props);
	free(map_props);
}
