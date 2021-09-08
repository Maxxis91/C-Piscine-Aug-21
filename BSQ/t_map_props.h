/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_props.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:20 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/06 23:57:42 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_PROPS_H
# define T_MAP_PROPS_H

# include <stdlib.h>
# include "ft_str.h"

typedef struct s_map_props_priv
{
	char	*seq;
	int		n;
	int		m;
}	t_map_props_priv;

typedef struct s_map_props
{
	t_map_props_priv	*priv;
}	t_map_props;

void		t_map_props_constructor(t_map_props	*map_props, int	len);
void		t_map_props_destructor(t_map_props	*map_props);
t_map_props	*t_map_props_new(int	len);
void		t_map_props_delete(t_map_props	*map_props);
void		t_map_props_set_seq(t_map_props	*map_props, char	*seq);
char		*t_map_props_get_seq(t_map_props	*map_props);
void		t_map_props_set_n(t_map_props	*map_props, int	n);
int			t_map_props_get_n(t_map_props	*map_props);
void		t_map_props_set_m(t_map_props	*map_proos,	int m);
int			t_map_props_get_m(t_map_props	*map_props);

#endif
