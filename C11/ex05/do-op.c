/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:39:36 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/01 23:06:35 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_funcs.h"
#include "ft_io.h"
#include "ft_ops.h"

int	main(int	argc, char	**argv)
{
	int		op;
	t_func	ops[5];

	if (argc != 4)
		return (0);
	op = is_op(argv[2]);
	if (op == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_arr_func(ops);
	if (ft_atoi(argv[3]) == 0 && op == 3)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (ft_atoi(argv[3]) == 0 && op == 4)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(ops[op](ft_atoi(argv[1]), ft_atoi(argv[3])));
	write(1, "\n", 1);
	return (0);
}
