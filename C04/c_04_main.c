/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_04_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:33:42 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/24 20:59:51 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_isspace(char  c);
int ft_atoi(char *str);
int ft_base_correct(char *base);
void ft_minint(long a, char *base);
void ft_putnbr_base(int nbr, char *base);
int ft_atoi_base_correct(char *base);
int ft_in_base(char c, char *base);
int ft_atoi_base(char *str, char *base);


int main(void)
{
	char *s0;
	int a02;
	char *a03;
	char *b04;
	char *a05;


	s0 = "abcdefghijklmnopqrstuvwxyz";
	a02 = 0;
	a03 = " ---+--+1234ab567";
	b04 = "0123456789ab";
	a05 = "--12df34ab567";

	printf("strlen: %lu\n", strlen(s0));
	printf("ft_strlen: %d\n", ft_strlen(s0));
	printf("ft_putstr: \n");
	ft_putstr (s0);
	printf("\nft_putnbr: %d \n", a02);
	ft_putnbr (a02);
	printf("\natoi: %d\n", atoi(a03));
	printf("ft_atoi: %d\n", ft_atoi(a03));
	printf("\nft_putnbr_base: %d, base %s:\n", a02, b04);
	ft_putnbr_base(a02, b04);
	printf("\nft_atoi_base: %s, base %s:\n", a05, b04);
   	printf("%d\n", ft_atoi_base(a05, b04));
	
	return (0);
}

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void ft_putnbr(int nb)
{
	char c;
	
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

int ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int ft_atoi(char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '+' || *str =='-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= 48 && *str <= 57))
	{
		res = res * 10 + *str - 48;
		str++;
	}
	res *= sign;
	return (res);
}

int ft_base_correct(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void ft_minint(long a, char *base)
{
	char c;
	
	if (a < 0)
	{
	write (1, "-", 1);
	ft_minint(-a, base);
	}
	if (a / ft_strlen(base) == 0 && a >= 0)
    {
    	c = base[a % ft_strlen(base)];
        write(1, &c, 1);
    }
    if (a / ft_strlen(base) > 0)
    {
    ft_minint(a / ft_strlen(base), base);
    ft_minint(a % ft_strlen(base), base);
    }
}

void ft_putnbr_base(int nbr, char *base)
{
	char c;

	if (ft_base_correct(base))
	{
		if (nbr == -2147483648)
	        ft_minint(nbr, base);
	    else
    	{
			if (nbr/ft_strlen(base) == 0 && nbr >= 0)
            {
                c = base[nbr%ft_strlen(base)];
                write(1, &c, 1);
            }
	        if (nbr < 0)
	        {
	            write (1, "-", 1);
	            ft_putnbr_base(-nbr, base);
	        }
	        if (nbr/ft_strlen(base) > 0)
	        {
	            ft_putnbr_base(nbr / ft_strlen(base), base);
	            ft_putnbr_base(nbr % ft_strlen(base), base);
	        }
	    }
	}
}

int ft_atoi_base_correct(char *base)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (base[i] == '\0' || base[i + 1] == '\0')
        return (0);
    while (base[i])
    {
        j = i + 1;
        if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
            return (0);
        if (base[i] < 32 || base[i] == 127)
            return (0);
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
    int res;
    int sign;

    res = 0;
    sign = 1;
    while (*str && ft_isspace(*str))
        str++;
    while (*str && (*str == '+' || *str == '-'))
    {
        if (*str == '-')
            sign *= -1;
		str++;
	}
    while (*str && ft_in_base(*str, base) >= 0)
	{
		res = res * ft_strlen(base) + ft_in_base(*str, base);
		str++;
    }
    res *= sign;
    return (res);
}

















