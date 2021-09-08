/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:55:43 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/31 22:58:40 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include "ft_err.h"

int	ft_atoi(char	*str, char	*argv)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	if (str[i])
	{
		ft_puterr(basename(argv), "illegal offset ", str);
		return (-1);
	}
	return (number);
}

void	print_names(int	i, int	argc, char	**argv)
{
	int	j;

	j = 0;
	if (argc > 4)
	{
		if (i > 3)
			write(1, "\n==> ", 5);
		else
			write(1, "==> ", 4);
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, " <==\n", 5);
	}
}

int	size_files(int	i, char	**argv)
{
	int		fd;
	char	buf[1];
	int		size;

	size = 0;
	fd = open(argv[i], O_RDONLY);
	if (fd < 0)
	{
		ft_puterr(basename(argv[0]), argv[i], strerror(errno));
		return (-1);
	}
	else
	{
		while (read(fd, buf, 1))
			size++;
	}
	close(fd);
	return (size);
}

int	disp_files(int	i, int	fd, int	argc, char	**argv)
{
	char	buf[1];
	int		offset;
	int		readed;
	int		size_file;

	size_file = size_files(i, argv);
	readed = 0;
	offset = ft_atoi(argv[2], argv[0]);
	if (offset == -1 || size_file == -1)
		return (-1);
	print_names(i, argc, argv);
	while (readed < (size_file - offset))
		readed += read(fd, buf, 1);
	while (read(fd, buf, 1))
		write(1, buf, 1);
	return (0);
}

int	main(int	argc, char	**argv)
{
	int	fd;
	int	i;
	int	j;

	i = 3;
	if (argc < 4)
		return (0);
	while (i < argc)
	{
		j = -1;
		fd = open(argv[i], O_RDWR);
		if (fd >= 0)
		{
			if (disp_files(i, fd, argc, argv) == -1)
				break ;
		}
		else
			ft_puterr(basename(argv[0]), argv[i], strerror(errno));
		close(fd);
		i++;
	}
	return (0);
}
