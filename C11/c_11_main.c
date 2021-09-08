/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_11_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:32:42 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 19:55:25 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_foreach(int *tab, int length, void(*f)(int));
void ft_putnbr(int   nb);
int *ft_map(int *tab, int length, int(*f)(int));
int ft_is_prime(int nb);
int ft_any(char **tab, int(*f)(char*));
int ft_check_any (char *str);
int ft_count_if(char **tab, int length, int(*f)(char*));
int ft_is_sort(int *tab, int length, int(*f)(int, int));
int ft_chk_sort(int a, int b);

int main(void)
{
    int tab[25];
    int i;
	int	*t1;
	char *s2[] = {"Fuck ", "da", "School", "42", NULL};
	int r2;
	int r3;
	int s4[] = {3, 2, 2, 1, 4, 1, 2};
//	int r4;

    i = 0;
    while (i < 25)
    {
        tab[i] = i;
        i++;
    }

	printf("\nforeach: \n");
    ft_foreach(tab, 25, &ft_putnbr);

	printf("\n\nft_map: \n");
	t1 = ft_map(tab, 25, &ft_is_prime);
	ft_foreach(t1, 25, &ft_putnbr);

	r2 = ft_any(s2, &ft_check_any);
	printf("\n\nft_any: %d\n", r2);

	r3 = ft_count_if(s2, 5, &ft_check_any);
	printf("\nft_count_if: %d\n", r3);

	printf("\nft_is_sort 1: \n");
		printf("%d\n", ft_is_sort(s4, 1, &ft_chk_sort));
    printf("\nft_is_sort 2: \n"); 
		printf("%d\n", ft_is_sort(s4, 2, &ft_chk_sort));
    printf("\nft_is_sort 3: \n"); 
		printf("%d\n", ft_is_sort(s4, 3, &ft_chk_sort));
    printf("\nft_is_sort 4: \n");
		printf("%d\n", ft_is_sort(s4, 4, &ft_chk_sort));
    printf("\nft_is_sort 5: \n"); 
	   	printf("%d\n", ft_is_sort(s4, 5, &ft_chk_sort));
    printf("\nft_is_sort 6: \n");
		printf("%d\n", ft_is_sort(s4, 6, &ft_chk_sort));

	return (0);
}

void    ft_putnbr(int   nb)
{
    char    c;

    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else
    {
        if (nb >= 0 && nb <= 9)
        {
            c = nb + '0';
            write(1, &c, 1);
        }
        if (nb < 0)
        {
            write (1, "-", 1);
            ft_putnbr(-nb);
        }
        if (nb > 9)
        {
            ft_putnbr(nb / 10);
            ft_putnbr(nb % 10);
        }
    }
}

int	ft_is_prime(int	nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while ((i * i) <= nb && i < 46340)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_any (char *str)
{
	if (str[0] >= 48 && str[0] <= 57)
		return (str[0]);
	else 
		return (0);	
}

int ft_chk_sort(int a, int b)
{
	return ((unsigned int)(a - b));
}

//	ex00

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	if (length > 0)
	{
		while (i < length)
		{
			f(tab[i]);
			i++;
		}
	}
}


//	ex01

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int *ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = (int *)malloc(sizeof(int) * length);
	if (res == 0)
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}


//	ex02

#ifndef NULL
# define NULL ((VOID *) 0)
#endif

int ft_any(char **tab, int(*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}


//	ex03

int ft_count_if(char **tab, int length, int(*f)(char*))
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (length < 0)
		return (0);
	while (tab[i] && i < length)
	{
		if (f(tab[i]) != 0)
			res++;
		i++;			
	}
	return (res);
}


//	ex04

int ft_sign(int nb)
{
	if (nb < 0)
		return (-1);
	if (nb > 0)
		return (1);
	return (0);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	int dir;
	int d2;

	i = 1;
	d2 = 0;
	if (length <= 0)
		return (0);
	if (length <= 2)	
		return (1);
	dir = ft_sign(f(tab[0], tab[1]));
	char c = tab[0] + 48;
	write(1, &c, 1);
	write(1, " ", 1);
	while (tab[i] && i < length)
	{
		d2 = ft_sign(f(tab[i - 1], tab[i]));
		if (dir == 0 && d2 != 0)
			dir = d2;
		c = tab[i] + 48;
		write(1, &c, 1);
		write(1, " ", 1);
		if ((dir < 0 && d2 > 0)	|| (dir > 0 && d2 < 0))
		{
			write (1, "\n", 1);
			return (0);
		}
		i++;
	}
	write (1, "\n", 1);
	return (1);
}


//	ex05

















