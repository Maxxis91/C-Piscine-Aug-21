/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:27:32 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/08 23:56:00 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "t_file.h"
#include "t_map.h"
#include "t_solve.h"

int	main(int	argc, char	**argv)
{
	t_map	*map;
	int		i;

	i = 1;
	if (argc == 1)
	{
		if (ft_load_map(&map, ""))
		{
			ft_solve(&map);
			ft_print_map(map);
			t_map_delete(map);
		}
		else
			ft_puterr("map error\n");
	}
	while (i < argc)
	{
		if (ft_load_map(&map, argv[i]))
		{
			ft_solve(&map);
			ft_print_map(map);
			t_map_delete(map);
		}
		else
			ft_puterr("map error\n");
		i++;
	}
	return (0);
}
