/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:16:49 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/29 00:53:03 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (res == 0)
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (!(s1[i] && s2[i]))
			break ;
		i++;
	}
	return (res);
}
