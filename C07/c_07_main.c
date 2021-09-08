/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_07_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:03:29 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/28 01:00:45 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

#ifndef NULL
# define NULL ((VOID *)0)
#endif

int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
int	*ft_range(int	min, int	max);
int ft_ultimate_range(int **range, int min, int max);
long  ft_res_size(int size, char **strs, char *sep);
char *ft_strjoin(int size, char **strs, char *sep);
char    *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main (void)
{

//	ex00	
	char *s0;
	char *d0;
	
	s0 = "Fuck 42";
	printf("s0: %s\n", s0);
	printf("strdup: %s\n", ft_strdup(s0));
	printf("----------------------------\n");
	
//	ex01	
	int min;
	int max;
	long i;
	long j;
	int *res;

	min = -28;
	max = 5;
	j = (unsigned int) (max - min);
	printf("min: %d, max: %d, cnt: %ld\n", min, max, j);
	res = ft_range(min, max);
	for (i = 0; i < j; i++)	printf("%d ", res[i]);
	printf("\n----------------------------\n");

//	ex02
    int min2;
    int max2;
    long i2;
    long j2;
	long k2;
    int *res2;

    min2 = -2;
    max2 = 20;
    j2 = (unsigned int) (max2 - min2);
    printf("min: %d, max: %d, cnt: %ld\n", min2, max2, j2);
    k2 = ft_ultimate_range(&res2, min2, max2);
	printf("size: %ld\n", k2);
    for (i2 = 0; i2 < j2; i2++)
    printf("%d ", *(res2 + i2));
    printf("\n----------------------------\n");

//	ex03
	int size = 4;
	char *strs[4] = {"Fuck", "42", "I", "said!"};
	char *sep;
	char *res3;	

	sep = ", bitch, ";
	printf("res_size: %ld\n", ft_res_size(size, strs, sep));
	res3 = ft_strjoin(size, strs, sep);
	printf("strjoin: %s\n", res3);
    printf("----------------------------\n");

//	ex04
	char *nbr4 = "Fb5";
	char *base_from = "0123456789ABCDEF";
	char *base_to = "01";
	char *res4;

	printf("convert %s from: %s to: %s\n", nbr4, base_from, base_to);
	res4 = ft_convert_base(nbr4, base_from, base_to);
	printf("%s\n",  res4);
	return (0);
}

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(char *src)
{
	char *res;
	int i;

	i = ft_strlen(src) + 1;
	res = malloc(i);
	if (res == NULL) 
		return (NULL);
	res = ft_strcpy(res, src);
	return (res);
}

int	*ft_range(int	min, int	max)
{
	int		*res;
	long	i;

	if (min >= max)
		return (NULL);
	res = (int	*)malloc(sizeof(res) * (unsigned int)(max - min));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	return (res);
}

int	ft_ultimate_range(int	**range, int	min, int	max)
{
	long	i;
	int 	*res;

	if (min >= max)
	{
	res = NULL;
	*range = res;
		return (0);
	}
	res = malloc(sizeof(int) * (unsigned int)(max - min));
	if (res == NULL)
		return (-1);
	i = 0;
    while (min < max)
    {
        res[i] = min;
        i++;
        min++;
    }
	*range = res;
    return (unsigned int)(i);
}

long ft_res_size(int size, char **strs, char *sep)
{
	int i;
	long res;

	i = 0;
	res = 0;
	while (i < size - 1)
	{
		res += ft_strlen(strs[i]);
		res += ft_strlen(sep);
		i++;
	}
	res += (ft_strlen(strs[i]) + 1);
	return (res);
}

char *ft_strjoin(int size, char **strs, char *sep)
				//	argc		argv		sep
{
	char *tmp;
	char *res;
	int i;

	if (size == 0)
	{
		res = malloc(sizeof(char));
		*res = '\0';
		return (res);
	}
	tmp = malloc(sizeof(char) * ft_res_size (size, strs, sep));
	if (tmp == NULL)
			return (NULL);
	res = tmp;
	i = 0;
	while (i < size - 1)
	{
		tmp = ft_strcpy(tmp, strs[i]);
		tmp += ft_strlen(strs[i]);
		tmp = ft_strcpy(tmp, sep);
		tmp += ft_strlen(sep);
		i++;
	}
	tmp = ft_strcpy(tmp, strs[i]);
	return (res);
}

int ft_power(int n, int p)
{
    int res;

    res = 1;
    if (p < 0)
        return (0);
    while (p > 0)
    {
        res *= n;
        p--;
    }
    return (res);
}

int ft_nbrlen(long   nbr, int   base, int   sign)
{
    int i;

    i = 0;
    if (sign == -1)
        i++;
    while (nbr > 0)
    {
        nbr /= base;
        i++;
    }
    return (i);
}

char    *ft_print(long  nbr, char   *base, char *res, int   sign)
{
    int i;
    int size;

    i = 0;
    size = ft_nbrlen(nbr, ft_strlen(base), sign);
    if (sign == -1)
        res[0] = '-';
    if (nbr == 0)
    {
        res[0] = base[0];
        res[1] = '\0';
    }
    while (nbr > 0)
    {
        res[(size - i - 1)] = base[nbr % ft_strlen(base)];
        i++;
        nbr /= ft_strlen(base);
    }
    return (res);
}

char    *ft_putnbr_base(long nbr, char *base, int sign)
{
    long    nb;
    char    *res;
    int     size;
    int     len;

    nb = nbr;
    size = ft_strlen(base);
    len = ft_nbrlen(nb, size, sign);
    res = malloc(sizeof(char) * (len + 1));
    if (res == NULL)
        return (NULL);
    res[len] = '\0';
    if ((sign == -1 && len == 1) || (len == 0 && sign == 1))
    {
        res[0] = base[0];
        return (res);
    }
    return (ft_print(nb, base, res, sign));
}

int base_correct(char *base)
{
    int i;
    int j;

    i = 0;
    if (base[0] == '\0' || base[1] == '\0')
        return (0);
    while (base[i] != '\0')
    {
        j = i + 1;
        while (base[j] != '\0')
        {
            if (base[i] == base[j] || base[j] == '+' || base[j] == '-'
                || base[j] == 32 || base[j] == 127
                || (base[j] >= 9 && base[j] <= 13))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

char    *check_sign(char *str, int *sign)
{
    *sign = 1;
    while (*str == '-' || *str == '+')
    {
        if (*str == '-')
            *sign *= -1;
        str++;
    }
    return (str);
}

char    *ft_atoi(char *str, char *base, int *sign, int *size)
{
    int i;
    int j;
    int valid;

    i = 0;
    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    str = check_sign(str, sign);
    while (*str != '\0')
    {
        j = -1;
        valid = 0;
        while (base[++j] != '\0')
            if (*str == base[j])
                valid = 1;
        if (valid == 0)
            break ;
        str++;
        i++;
    }
    *size = i;
    return (str - i);
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    long int    nb;
    int         sign;
    int         size;
    int         ps;
    int         n;

    nb = 0;
    ps = 0;
    nbr = ft_atoi(nbr, base_from, &sign, &size);
    if (base_correct(base_from) == 0 || base_correct(base_to) == 0)
        return (NULL);
    while (ps < size)
    {
        n = 0;
        while (base_from[n] != nbr[ps])
            n++;
        nb += n * ft_power(ft_strlen(base_from), (size - ps - 1));
        ps++;
    }
    return (ft_putnbr_base(nb, base_to, sign));
}

