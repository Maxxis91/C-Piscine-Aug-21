/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_03_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:41:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/08/23 22:00:16 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char	*s1, char	*s2);

int	ft_strcmp(char	*s1, char	*s2)
{
	int i;
	int res;
	
	i = 0;
	res = 0;
	while (res == 0)
	{
		res = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (res);
}

int ft_strncmp(char *s1, char *s2, unsigned int n);

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int res;

	i = 0;
	res = 0;
	while (res == 0)
	{
		res = s1[i] - s2[i]; //Вот тут надо было привести s[i] к типу unsigned char *, чтобы работало и на extended ASCII
		if (s1[i] == '\0' || s2[i] == '\0' || i == n - 1)
			break ;
		i++;
	}	
	return (res);
}

char *ft_strcat(char *dest, char *src);

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char *ft_strncat(char *dest, char *src, unsigned int nb);

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		if (j == nb - 1)
			break ;
		j++;
	}
	//БЛЯ ЗАБЫЛ ДОБАВИТЬ dest[i+j] = '\0', и еще удивляюсь, что тест не прошел! Пиздец.
	return (dest);
}

char *ft_strstr(char *str, char *to_find);

char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

unsigned int        slen(char *str);

unsigned int		slen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int        ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int sz_d;
	unsigned int sz_s;

	i = slen(dest);
	j = 0;
	sz_d = slen(dest);
	sz_s = slen(src);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size == 0 || size < sz_d)
		return (sz_s + size);
	else
		return (sz_d + sz_s);
}


int main(void)
{
	char *s1;
	char *s2;
	char s3[50] = "42";
	char s4[50] = " Sucks!";

	s1 = "abcde abcf";
	s2 = "iu";

	printf("strcmp: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("strncmp: %d\n", strncmp(s1, s2, 3));
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 3));
	printf("strcat: %s\n", strcat(s3, s4));
	printf("ft_strcat: %s\n", ft_strcat(s3, s4));
	printf("strncat: %s\n", strncat(s3, s4, 7));
	printf("ft_strncat: %s\n", ft_strncat(s3, s4, 7));
	printf("strstr: %s\n", strstr(s1, s2));
	printf("ft_strstr: %s\n", ft_strstr(s1, s2));
	printf("strlcat: %lu: %s\n", strlcat(s3, s4, 50), s3);
	printf("ft_strlcat: %d: %s\n", ft_strlcat(s3, s4, 50), s3);

	return (0);
}
