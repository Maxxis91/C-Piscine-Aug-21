/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:56:39 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/20 00:50:49 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** C_00 ************************************ */

//#include <unistd.h>
//#include <stdio.h>


void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int	n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int	nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

void	ft_is_negative(int	n)
{
	char	c;

	if (n < 0)
		c = 'N';
	else
		c = 'P';
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int		i;
	char	c;

	i = 12;
	while (i <= 789)
	{
		if (((i / 100) < ((i / 10)) % 10) && (((i / 10) % 10) < (i % 10)))
		{
			c = (i / 100) + '0';
			write(1, &c, 1);
			c = ((i / 10) % 10) + '0';
			write(1, &c, 1);
			c = (i % 10) + '0';
			write(1, &c, 1);
			if (i != 789)
				write(1, ", ", 2);
		}
		i++;
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			c = (i / 10) + '0';
			write(1, &c, 1);
			c = (i % 10) + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			c = (j / 10) + '0';
			write(1, &c, 1);
			c = (j % 10) + '0';
			write(1, &c, 1);
			if (i != 98 || j != 99)
				write(1, ", ", 1);
			j++;
		}
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		c = (nb % 10) + '0';
		write (1, &c, 1);
	}
}

int	main(void)
{
	char	c;

	c = 'Z';
	ft_putchar(c);
	c = '\n';
	write(1, &c, 1);
	ft_print_alphabet();
	write(1, &c, 1);
	ft_print_reverse_alphabet();
	write(1, &c, 1);
	ft_print_numbers();
	write(1, &c, 1);
	ft_is_negative(-1);
	write(1, &c, 1);
	ft_is_negative(0);
	write(1, &c, 1);
	ft_is_negative(1);
	write(1, &c, 1);
	ft_print_comb();
	write(1, &c, 1);
	ft_print_comb2();
	write(1, &c, 1);
	ft_putnbr(-2147483648);
	write(1, &c, 1);
	return (0);
}
