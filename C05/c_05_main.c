/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_05_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:59:43 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/25 15:39:06 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int nb);
int ft_is_prime(int nb);
int ft_find_next_prime(int nb);

int main(void)
{
	int a0 = 46340;
	int a2 = 2;
	int index = 8;
	int a5 = 2147395601;
	int a6 = 323;
	int a7 = 2147483000;

	printf("it_fact: %d\n", ft_iterative_factorial(a0));
	printf("re_fact: %d\n", ft_recursive_factorial(a0));
	printf("it_pwr: %d\n", ft_iterative_power(a0, a2));
	printf("re_pwr: %d\n", ft_recursive_power(a0, a2));
	printf("fib #%d: %d\n", index, ft_fibonacci(index));
	printf("sqrt %d: %d\n", a5, ft_sqrt(a5)); 
	printf("prime %d: %d\n", a6, ft_is_prime(a6));
	printf("next prime for %d: %d\n", a7, ft_find_next_prime(a7)); 
	return (0);
}

int ft_iterative_factorial(int nb)
{
	int i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = nb;
	while (i > 1)
		nb = nb * (--i);
	return (nb);
}

int ft_recursive_factorial(int nb)
{
    if (nb < 0)
    	return (0);
    if (nb == 0 || nb == 1)
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));
}

int ft_iterative_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	return (res);
}

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int ft_sqrt(int nb)
{
	int i;
	int res;

	i = 1;
	res = 1;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb && i < 46340)
		i++;
	if ((i * i) == nb)
		return (i);
	else 
		return (0);
}

int ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while ((i * i) < nb && i < 46340)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
