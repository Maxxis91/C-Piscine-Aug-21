/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:37:41 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 19:33:07 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sign(int	nb)
{
	if (nb < 0)
		return (-1);
	if (nb > 0)
		return (1);
	return (0);
}

int	ft_is_sort(int	*tab, int	length, int(*f)(int, int))
{
	int	i;
	int	dir;
	int	d2;

	i = 1;
	d2 = 0;
	if (length <= 0)
		return (0);
	if (length <= 2)
		return (1);
	dir = ft_sign(f(tab[0], tab[1]));
	while (tab[i] && i < length)
	{
		d2 = ft_sign(f(tab[i - 1], tab[i]));
		if (dir == 0 && d2 != 0)
			dir = d2;
		if ((dir < 0 && d2 > 0) || (dir > 0 && d2 < 0))
			return (0);
		i++;
	}
	return (1);
}
