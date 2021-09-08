/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:50:51 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/25 22:53:17 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int	nb, int	power);

int	ft_recursive_power(int	nb, int	power)
{
	if (power < 0 && (nb == 1 || nb == -1))
		return (nb * ft_recursive_power(nb, power + 1));
	else
	{
		if (power < 0)
			return (0);
		if (power == 0)
			return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
