/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:24:24 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 17:31:03 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char	**tab, int	length, int(*f)(char*))
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (length < 0)
		return (0);
	while (tab[i] && i < length)
	{
		if (f(tab[i]) != 0)
			res++;
		i++;
	}
	return (res);
}
