/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:38:33 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/19 20:40:52 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_is_negative(int	n);

void	ft_is_negative(int	n)
{
	char	c;

	if (n < 0)
		c = 'N';
	else
		c = 'P';
	write(1, &c, 1);
}
