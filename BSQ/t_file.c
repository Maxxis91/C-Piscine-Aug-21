/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 01:00:06 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 23:54:42 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_file.h"

void	str_flush(char	**str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		(*str)[i] = '\0';
		i++;
	}
}

int	ft_read_std(char	***dest)
{
	char	buf[1];
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char));
	while (read(0, buf, 1))
	{
		if (buf[0] != '\n')
			ft_append_chr(&str, buf[0]);
		else
		{
			i++;
			*dest = ft_append_str(*dest, str, i);
			str_flush(&str);
			free(str);
			str = (char *)malloc(sizeof(char));
		}
	}
	free(str);
	return (i);
}

int	ft_read_file(char	***dest, char	*fname)
{
	int		fd;
	char	buf[1];
	char	*str;
	int		i;

	i = 0;
	fd = open(fname, O_RDONLY);
	str = (char *)malloc(sizeof(char));
	while (read(fd, buf, 1))
	{
		if (buf[0] != '\n')
			ft_append_chr(&str, buf[0]);
		else
		{
			i++;
			*dest = ft_append_str(*dest, str, i);
			str_flush(&str);
			free(str);
			str = (char *)malloc(sizeof(char));
		}
	}
	free(str);
	close(fd);
	return (i);
}

int	ft_load_map(t_map	**map, char	*argv)
{
	char	**tmp;
	int		lines;
	char	**p;
	int		res;

	res = 1;
	tmp = (char **)malloc(sizeof (char *));
	if (ft_strlen(argv) == 0)
		lines = ft_read_std(&tmp);
	else
		lines = ft_read_file(&tmp, argv);
	if (is_valid(tmp, lines - 1))
	{
		(*map) = t_map_new(tmp[0], lines - 1, ft_strlen(tmp[1]));
		p = &(tmp[1]);
		t_map_set_elem((*map), p);
	}
	else
		res = 0;
	while (--lines >= 0)
		free(tmp[lines]);
	free(tmp);
	return (res);
}

void	ft_print_map(t_map	*map)
{
	int	i;

	i = 0;
	while (i < t_map_props_get_n((t_map_props *)map))
	{
		ft_putstr(t_map_get_elem(map)[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}
