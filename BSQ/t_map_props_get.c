/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_props_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:34:47 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/06 23:00:54 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map_props.h"

char	*t_map_props_get_seq(t_map_props	*map_props)
{
	return (map_props->priv->seq);
}

int	t_map_props_get_n(t_map_props	*map_props)
{
	return (map_props->priv->n);
}

int	t_map_props_get_m(t_map_props	*map_props)
{
	return (map_props->priv->m);
}
