/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_08_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:08:15 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/28 23:24:24 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	ex00

#ifndef FT_H
# define FT_H

#include <unistd.h>

void	ft_putchar(char	c);
void	ft_swap(int	*a, int	*b);
void	ft_putstr(char	*str);
int		ft_strlen(char	*str);
int		ft_strcmp(char	*s1, char	*s2);

#endif

//	ex01

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

t_bool	EVEN(int	nbr)
{
	if (nbr % 2 == 0)
		return (TRUE);
	else
		return (FALSE);
}

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0

#endif

#include "ft_boolean.h"

void    ft_putstr(char  *str)
{
    while (*str)
        write(1, str++, 1);
}

t_bool  ft_is_even(int  nbr)
{
    return ((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int    argc, char  **argv)
{
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE)
        ft_putstr(EVEN_MSG);
    else
        ft_putstr(ODD_MSG);
    return (SUCCESS);
}

//	ex02

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

#endif

//	ex03

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int x;
	int y;
}				t_point;
#endif

#include "ft_point.h"

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(void)
{
	t_point point;

	set_point(&point);
	return(0);
}

//	ex04

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
}			t_stock_str

#endif

#include <stdlib.h>
#include "ft_stock_str.h"

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int ft_strlen(char  *str)
{
    unsigned int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    char    *res;
    int     i;

    i = ft_strlen(src) + 1;
    res = (char *)malloc(sizeof(char) * i);
    if (res == NULL)
        return (NULL);
    i = 0;
    while (src[i] != '\0')
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

struct s_stock_str  *ft_strs_to_tab(int ac, char    **av)
{
    t_stock_str *res;
    int         i;

    if (ac < 0)
        return (NULL);
    res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
    if (res == NULL)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        res[i].size = ft_strlen(av[i]);
        res[i].str = av[i];
        res[i].copy = ft_strdup(av[i]);
        i++;
    }
    res[i].size = 1;
    res[i].str = 0;
    res[i].copy = 0;
    return (res);
}

//	ex05

#include <unistd.h>
#include "ft_stock_str.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char  *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_putnbr(int   nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + 48);
}

void    ft_show_tab(struct s_stock_str *par)
{
    int i;

    i = 0;
    while (par[i].str != 0)
    {
        ft_putstr(par[i].str);
        ft_putchar('\n');
        ft_putnbr(par[i].size);
        ft_putchar('\n');
        ft_putstr(par[i].copy);
        ft_putchar('\n');
        i++;
    }
}

#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int  ac, char    **av);
void ft_show_tab(struct s_stock_str *par);

int main(void)
{
int ac = 4;
char *strs[4] = {"Fuck", "42", "I", "said!"};
t_stock_str *tab;

tab = ft_strs_to_tab(ac, strs);
ft_show_tab(tab);
return (0);
}
