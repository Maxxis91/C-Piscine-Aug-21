/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_02_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:54:10 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/21 23:41:26 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *dest, char *src);

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int ft_str_is_alpha(char    *str);

int ft_str_is_alpha(char    *str)
{
    int i;

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

int ft_str_is_numeric(char *str);

int ft_str_is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
        {
            i=0;
            break ;
        }
    }
    if (i == 0 && str[i] != '\0')
        return (i);
    else
        return (1);
}

int ft_str_is_lowercase(char    *str);

int ft_str_is_lowercase(char    *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
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

int ft_str_is_uppercase(char    *str);

int ft_str_is_uppercase(char    *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
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

int ft_str_is_printable(char    *str);

int ft_str_is_printable(char    *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] < 32 || str[i] > 126)
            return (0);
        i++;
    }
    return(1);
}

char    *ft_strupcase(char  *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}

char    *ft_strlowcase(char *str);

char    *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    i++;
    }
    return (str);
}

char    *ft_strcapitalize(char *str);

char    *ft_strcapitalize(char *str)
{
    int i;

    if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    i = 1;
    while (str[i] != '\0')
    {
        if (((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= 'A' && str[i] <= 'Z'))
            && (str[i - 1] < '0'
                || (str[i - 1] > '9' && str[i - 1] < 'A')
                || (str[i - 1] > 'Z' && str[i - 1] < 'a')
                || str[i - 1] > 'z'))
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        ++i;
    }
    return (str);
}

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int    len;
    unsigned int i;

    len = 0;
    while (src[len] != '\0')
        len++;
    i = 0;
    while (src[i] != '\0' && i < (size - 1))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (len);
}

void    ft_init_hex_table(char base[])
{
    base[0] = '0';
    base[1] = '1';
    base[2] = '2';
    base[3] = '3';
    base[4] = '4';
    base[5] = '5';
    base[6] = '6';
    base[7] = '7';
    base[8] = '8';
    base[9] = '9';
    base[10] = 'a';
    base[11] = 'b';
    base[12] = 'c';
    base[13] = 'd';
    base[14] = 'e';
    base[15] = 'f';
}

void    ft_putstr_non_printable(char *str)
{
    int     i;
    char    a;
    char    b;
    char    base[16];

    ft_init_hex_table(base);
    i = -1;
    while (str[++i] != '\0')
        if ((str[i] >= 32 && str[i] <= 126))
            write(1, &str[i], 1);
    else
    {
        a = base[str[i] / 16];
        b = base[str[i] % 16];
        write(1, "\\", 1);
        write(1, &a, 1);
        write(1, &b, 1);
    }
}

int main(void)
{
	char d00[48];
	char s00[] = "AAAa a=/**AA 42fuck FUCKK\n";

	printf("strcpy: %s\n", ft_strcpy(d00, s00));
	printf("strncpy: %s\n", ft_strncpy(d00, s00, strlen(s00)));
	printf("is_alpha: %d\n", ft_str_is_alpha(s00));
	printf("is_num: %d\n", ft_str_is_numeric(s00));
	printf("is_low: %d\n", ft_str_is_lowercase(s00));
	printf("is_up: %d\n", ft_str_is_uppercase(s00));
	printf("is_prn: %d\n", ft_str_is_printable(s00));
	printf("up: %s\n", ft_strupcase(s00));
	printf("low: %s\n", ft_strlowcase(s00));
	printf("capit: %s\n", ft_strcapitalize(s00));
	printf("strlcpy: %d: %s\n", ft_strlcpy(d00, s00, 48), d00);
	printf("putnp: \n");
	ft_putstr_non_printable(s00);

	return (0);
}
