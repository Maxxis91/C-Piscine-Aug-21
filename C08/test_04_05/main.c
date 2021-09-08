/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 23:16:07 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/28 23:20:07 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int	ac, char	**av);
void				ft_show_tab(struct s_stock_str	*par);

int	main(void)
{
	int			ac;
	char		*strs[4];
	t_stock_str	*tab;

	ac = 4;
	strs = {"Fuck", "42", "I", "said!"};
	tab = ft_strs_to_tab(ac, strs);
	ft_show_tab(tab);
	return (0);
}
