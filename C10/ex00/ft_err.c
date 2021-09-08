/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:30:30 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/30 21:19:56 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_err.h"

void	_ERROR(int _errno)
{
	if (_errno == 0)
		write (2, "File name missing.\n", 19);
	if (_errno == 1)
		write (2, "Too many arguments.\n", 20);
	if (_errno == 2)
		write (2, "Cannot read file.\n", 18);
}
