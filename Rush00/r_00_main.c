/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_00_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 00:06:47 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/22 02:14:50 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Teamlead: Rtemplet. R = 18. 18 % 5 = 3. Assignment: Rush03.
/****************************************************************
 * 																*
 *	x - width, y - length.										*
 *	Characters used: A B C										*
 *																*
 * A: top and bottom left corners.								*
 * B: all margins.												*
 * C: top and bottom right corners.								*
 *																*
 *																*
 * rush (5,3):	rush(5,1):	rush(1,1):	rush(1,5):	rush(4,4):	*
 * 																*
 * ABBBC		ABBBC		A			A			ABBC		*
 * B   B								B			B  B		*
 * ABBBC								B			B  B		*
 *										B			ABBC		*
 *										A						*
 *																*
 * *************************************************************/


#include <unistd.h>

void	ft_putchar(char	c);

void	ft_putchar(char	c)
{
    write(1, &c, 1);
}

void line (int len, char a, char b, char c)
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
	int j;

	j = 1;
	if (x * y <= 0)
		ft_putchar('\n');
	else
	{
		line (x, 'A', 'B', 'C');
		while (j < y - 1)
		{
			line(x, 'B', ' ', 'B');
			j++;
		}
		if (j < y)
			line (x, 'A', 'B', 'C');
	}
}

int	main(void)
{
	rush(5,3);
	ft_putchar('\n');
	rush(5,1);
	ft_putchar('\n');
	rush(1,1);
	ft_putchar('\n');
	rush(1,5);
	ft_putchar('\n');
	rush(4,4);
	ft_putchar('\n');
	rush(0,0);
	return (0);
}

