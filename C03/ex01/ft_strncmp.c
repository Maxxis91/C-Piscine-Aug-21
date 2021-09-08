/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:21:09 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/22 15:35:35 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char	*s1, char	*s2, unsigned int	n);

int	ft_strncmp(char	*s1, char	*s2, unsigned int	n)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (res == 0)
	{
		res = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0' || i == n - 1)
			break ;
		i++;
	}
	return (res);
}
