/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_06_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:51:44 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/26 23:24:17 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char  *str);
int ft_strcmp(char *s1, char *s2);
void ft_print_params(int ac, char **av);

int main(int argc, char **argv)
{
	int i0;
	int j0;	

	i0 = 0;
	while (i0 < argc && i0 == 0)	
	{
		j0 = 0;
		while (argv[i0][j0])
	    {
    	    write(1, &argv[i0][j0], 1);
	        j0++;
	    }
		i0++;
	    write(1, "\n", 1);
	}

    write(1, "---------\n", 10);

	int i1;
	int j1;

	i1 = 1;
	j1 = 0;

    while (i1 < argc)
    {	
		j1 = 0;
        while (argv[i1][j1] != '\0')
        {
            write(1, &argv[i1][j1], 1);
            j1++;
        }
		i1++;
	    write(1, "\n", 1);
    }

    write(1, "---------\n", 10);
	
    int i2;
    int j2;

    i2 = argc - 1;
    j2 = 0;

    while (i2 > 0)
    {
        j2 = 0;
        while (argv[i2][j2] != '\0')
        {
            write(1, &argv[i2][j2], 1);
            j2++;
        }
        i2--;
        write(1, "\n", 1);
    }

    write(1, "---------\n", 10);

	int i3;
	char *tmp;
	
	i3 = 1;
	while (i3 < argc - 1)
	{
		if (ft_strcmp(argv[i3], argv[i3 + 1]) > 0)
		{
			tmp = argv[i3];
			argv[i3] = argv[i3+1];
			argv[i3 + 1] = tmp;
			i3 = 0;
		}
		i3++;
	}
	ft_print_params(argc, argv);
	return (0);
}

void ft_putstr(char  *str)
{
	int i;

	i = 0;
 	while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_strcmp(char *s1, char *s2)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (res == 0)
    {
        res = (unsigned char)s1[i] - (unsigned char)s2[i];
        if (s1[i] == '\0' || s2[i] == '\0')
            break ;
        i++;
    }
    return (res);
}

void ft_print_params(int ac, char **av)
{
	int i;

    i = 1;
    while (i < ac)
    {
        ft_putstr(av[i]);
        i++;
        write(1, "\n", 1);
    }
}
