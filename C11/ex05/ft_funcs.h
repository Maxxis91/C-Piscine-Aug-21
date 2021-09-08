/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:48:52 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 23:08:26 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCS_H
# define FT_FUNCS_H

typedef long(*t_func)(int, int);

void	ft_arr_func(t_func *ops);
int		ft_strcmp(char	*s1, char	*s2);
int		is_op(char *str);

#endif
