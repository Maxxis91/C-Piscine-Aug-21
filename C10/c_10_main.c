/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_10_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:49:07 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/31 23:04:59 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	ex00

//	ft_err.h

#ifndef FT_ERR_H
# define FT_ERR_H

void    _ERROR(int _errno);

#endif

//	ft_err.c

#include <unistd.h>
#include "ft_err.h"

void    _ERROR(int _errno)
{
    if (_errno == 0)
        write (2, "File name missing.\n", 19);
    if (_errno == 1)
        write (2, "Too many arguments.\n", 20);
    if (_errno == 2)
        write (2, "Cannot read file.\n", 18);
}

#include <fcntl.h>
#include <unistd.h>
#include "err.h"

//	ft_display_file.c

int main(int    argc, char  **argv)
{
    int     fd;
    char    buf[1];

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

//	Makefile:

.PHONY: all clean fclean

CC = gcc
PATH_SRC = ./
SRC = ft_display_file.c ft_err.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
PATH_HEAD = ./
HEAD = ft_err.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
FLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
    $(CC) $(FLAGS) -include $(HEADS) -c $*.c -o $*.o

$(NAME): $(OBJS)
    $(CC) $(FLAGS) $^ -o $(NAME)

clean:
    rm -f *.o

fclean: clean
    rm -f $(NAME)


//	ex01

//	ft_err.h

#ifndef FT_ERR_H
# define FT_ERR_H

# include <unistd.h>

void	ft_puterr(char	*basename, char	*av, char	*msg);

#endif

//	ft_err.c

#include <unistd.h>
#include "ft_err.h"

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_puterr(char	*basename, char	*av, char	*msg)
{
	ft_putstr(basename);
	ft_putstr(": ");
	ft_putstr(av);
	ft_putstr(": ");
	ft_putstr(msg);
	ft_putstr("\n");
}

//	ft_cat.c

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

//	Makefile

.PHONY: all clean fclean

CC = gcc
PATH_SRC = ./
SRC = ft_cat.c ft_err.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
PATH_HEAD = ./
HEAD = ft_err.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
FLAGS = -Wall -Wextra -Werror
NAME = ft_cat
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -include $(HEADS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)


//	ex02

//	ft_err.h

#ifndef FT_ERR_H
# define FT_ERR_H

# include <unistd.h>

void	ft_puterr(char	*basename, char	*av, char	*msg);

#endif

//	ft_err.c

#include <unistd.h>
#include "ft_err.h"
#include <string.h>

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (res == 0)
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (!(s1[i] && s2[i]))
			break ;
		i++;
	}
	return (res);
}

void	ft_puterr(char	*basename, char	*av, char	*msg)
{
	if (!ft_strcmp(msg, strerror(21)))
		return ;
	ft_putstr(basename);
	ft_putstr(": ");
	ft_putstr(av);
	if (ft_strcmp(av, "illegal offset "))
		ft_putstr(": ");
	else
		ft_putstr("-- ");
	ft_putstr(msg);
	ft_putstr("\n");
}

//	ft_tail.c

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

//  Makefile

.PHONY: all clean fclean

CC = gcc
PATH_SRC = ./
SRC = ft_tail.c ft_err.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
PATH_HEAD = ./
HEAD = ft_err.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
FLAGS = -Wall -Wextra -Werror
NAME = ft_tail
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
    $(CC) $(FLAGS) -include $(HEADS) -c $*.c -o $*.o

$(NAME): $(OBJS)
    $(CC) $(FLAGS) $^ -o $(NAME)

clean:
    rm -f *.o

fclean: clean
    rm -f $(NAME)
