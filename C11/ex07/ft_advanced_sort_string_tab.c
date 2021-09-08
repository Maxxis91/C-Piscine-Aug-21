/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:34:51 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 23:39:40 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*tmp;
	int		ordered;
	int		c;

	ordered = 0;
	while (!ordered)
	{
		i = 0;
		ordered = 1;
		while (tab[++i])
		{
			c = cmp(tab[i - 1], tab[i]);
			if (c > 0)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
				ordered = 0;
			}
		}
	}
}
