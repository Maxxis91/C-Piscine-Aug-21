/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:31:08 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/30 21:20:44 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "err.h"

int	main(int	argc, char	**argv)
{
	int		fd;
	char	buf[1];

	if (argc == 1)
	{
		_ERROR(0);
		return (0);
	}
	if (argc > 2)
	{
		_ERROR(1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		_ERROR(2);
		return (0);
	}
	while (read(fd, buf, sizeof (buf)))
		write(1, buf, sizeof (buf));
	close(fd);
	return (0);
}
