/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_props_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:30:13 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 05:15:08 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map_props.h"

void	t_map_props_set_seq(t_map_props	*map_props, char	*seq)
{
	char	*p;

	p = map_props->priv->seq;
	map_props->priv->seq = ft_strdup(seq);
	free(p);
}

void	t_map_props_set_n(t_map_props	*map_props, int	n)
{
	map_props->priv->n = n;
}

void	t_map_props_set_m(t_map_props	*map_props, int	m)
{
	map_props->priv->m = m;
}
