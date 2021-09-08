/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:28:04 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 00:23:33 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_map_props.h"

typedef struct s_map_priv
{
	char	**elem;
}	t_map_priv;

typedef struct s_map
{
	t_map_props	parent;
	t_map_priv	*priv;
}	t_map;

void	t_map_constructor(t_map	*map, int	len, int	n, int	m);
void	t_map_destructor(t_map	*map);
t_map	*t_map_new(char	*seq, int	n, int	m);
void	t_map_delete(t_map	*map);
void	t_map_set_elem(t_map	*map, char	**elem);
char	**t_map_get_elem(t_map	*map);

#endif
