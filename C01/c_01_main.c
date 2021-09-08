/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_01_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:02:58 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/20 23:15:15 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ft(int	*nbr);

void	ft_ft(int	*nbr)
{
	*nbr = 42;
}

void	ft_ultimate_ft(int	*********nbr);

void	ft_ultimate_ft(int	*********nbr)
{
	*********nbr = 42;
}

void	ft_swap(int	*a, int	*b);

void	ft_swap(int	*a, int	*b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void    ft_div_mod(int  a, int  b, int  *div, int   *mod);

void    ft_div_mod(int  a, int  b, int  *div, int   *mod)
{
    *div = a / b;
    *mod = a % b;
}

void    ft_ultimate_div_mod(int *a, int *b);

void    ft_ultimate_div_mod(int *a, int *b)
{
    int div;
    int mod;

    div = *a / *b;
    mod = *a % *b;

    *a = div;
    *b = mod;
}

void	ft_putstr(char	*str);

void    ft_putstr(char	*str)
{
int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_strlen(char  *str);

int ft_strlen(char  *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void	ft_rev_int_tab(int	*tab, int	size);

void	ft_rev_int_tab(int	*tab, int	size)
{
	int		i;
	int		tmp;

	i = 0;
	size--;
	while (i < size)
	{
		tmp = tab[i];
		tab[i] = tab[size];
		tab[size] = tmp;
		i++;
		size--;
	}
}

void    ft_sort_int_tab(int *tab, int   size);

void    ft_sort_int_tab(int *tab, int   size)
{
    int i;
    int s;

    i = 0;
    while (i < (size - 1))
    {
        if (tab[i] > tab[i+1])
        {
            s = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = s;
            i = 0;
        }
        else
            i++;
    }
}

int	main(void)
{
	int a;
	int b;
	int div;
	int mod;
	char *s;
	int t[7];

	div = 0;
	while (div < 7) {
	t[div] = 10 - div;
	div++; }

	a = 100;
	b = 15;
	div = 0;
	mod = 0;
	s = "LALA";
	ft_ultimate_div_mod(&a, &b);
	printf("%d, ", a);
	printf("%d\n", ft_strlen(s));
	ft_rev_int_tab(t, 7);
	ft_sort_int_tab(t,7);
	div = 0;
	while (div <= 6) {printf("%d, ", t[div]); div++;}
	printf("%s", s );
	
	
	return (0);
}
