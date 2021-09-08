/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:20:34 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 19:11:53 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALID_H
# define FT_VALID_H

# include "ft_str.h"

void	ft_puterr(char	*str);
int		check_seq(char	*seq);
int		is_valid(char	**tmp, int	lines);

#endif
