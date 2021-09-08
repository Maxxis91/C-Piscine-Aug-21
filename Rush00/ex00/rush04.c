/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 00:49:52 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/22 14:24:39 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char	c);

void	line(int	len, char	a, char	b, char	c)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i == 0)
		{
			ft_putchar (a);
			if (i == len - 1)
				ft_putchar('\n');
		}
		if (i > 0 && i < len - 1)
			ft_putchar (b);
		if (i > 0 && i == len - 1)
		{
			ft_putchar (c);
			ft_putchar ('\n');
		}
		i++;
	}
}

void	rush(int	x, int	y)
{
	int	j;

	j = 1;
	line (x, 'A', 'B', 'C');
	while (j < y - 1)
	{
		line(x, 'B', ' ', 'B');
		j++;
	}
	if (j < y)
		line (x, 'C', 'B', 'A');
}
