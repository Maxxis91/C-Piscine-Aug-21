/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 00:18:47 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 18:44:27 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FILE_H
# define T_FILE_H

# include <stdlib.h>
# include <fcntl.h>
# include "ft_str.h"
# include "t_map.h"
# include "ft_valid.h"

void	str_flush(char	**str);
int		ft_read_std(char	***dest);
int		ft_read_file(char	***dest, char	*fname);
int		ft_load_map(t_map	**map, char	*argv);
void	ft_print_map(t_map	*map);

#endif
