/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:14:00 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/20 19:16:02 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int	*a, int	*b);

void	ft_swap(int	*a, int	*b)
{
	int	tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}
