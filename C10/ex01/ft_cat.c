/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:45:57 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/30 23:17:04 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include "ft_err.h"

void	disp_stdin(void)
{
	char	buf[1];

	while (read(0, buf, 1))
		write(1, buf, 1);
}

int	is_stdin(char	*av)
{
	if (av[0] == '-' && av[1] == '\0')
		return (1);
	return (0);
}

void	disp_files(int	argc, char	**argv)
{
	extern int	errno;
	char		buf[1];
	int			fd;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (is_stdin(argv[i]))
			disp_stdin();
		else
		{
			fd = open(argv[i], O_RDWR);
			if (fd < 0)
				ft_puterr(basename(argv[0]), argv[i], strerror(errno));
			else
			{
				while (read(fd, buf, 1))
					write(1, buf, 1);
			}
			close(fd);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		disp_stdin();
	disp_files(argc, argv);
	return (0);
}
