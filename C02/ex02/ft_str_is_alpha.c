/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:37:19 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/22 17:24:45 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char	*str);

int	ft_str_is_alpha(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > '@' && str[i] < '[') || (str[i] > '`' && str[i] < '{'))
			i++;
		else
		{
			i = 0;
			break ;
		}
	}
	if (i == 0 && str[i] != '\0')
		return (i);
	else
		return (1);
}
