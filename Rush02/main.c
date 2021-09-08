/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:36:19 by gmelissi          #+#    #+#             */
/*   Updated: 2021/09/05 21:07:47 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_btree.h" //функции для работы с деревьями
#include "ft_list.h" //функции для работы со списками
#include "ft_io.h" //функции ввода-вывода

char	*check_nbr(char	*str) //проверка, что входная строка - положительное целое число. если да - чистит от +-. если нет - возвращает NULL.
{
	char	*res;
	int		sign;
	int		i;
	int		j;

	sign = 1;
	i = 0;
	j = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-')) //проверяем первые плюсы и минусы. 
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign == -1) //если число отрицательное - ошибка.	
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	while (str[i]) //начинаем просмотр с первого символа после +-
	{
		if (str[i] < 48 || str[i] > 57)
			return (NULL); //встретили не цифру - ошибка.
		res[j] = str[i]; //переписываем цифры в res
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char	*str, int	pos, int	n) //возвращает от 1 до n символов исходной строки, кончая pos-1-м.
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(sizeof(char) * (n + 1));
	i = ft_max(0, pos - n);
	j = 0;
	while (i < pos)
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

t_list	**parse_nbr(char	*nbr) //принимает на вход строку, возвращает список триплетов, сортированный по 10^3 по убыванию.
{
	long	len; //длина строки
	long	n_elem; //сколько будет триплетов - aka элементов в списке-стеке
	int		i; //счетчик степеней тысячи. 1000^0 = 1, 1000^1 = 1000, ... 1000^11 = 10^33, 1000^12 = 10^36, 1000^13 = 10^39
	t_list	**res; //результирующий список.
	t_list	*tmp;

	tmp = NULL;
	len = ft_strlen(nbr); //количество разрядов входной строки
	n_elem = len / 3 + ((len % 3) > 0); //столько целых троек в записи входного числа, если TRUE == 1, а FALSE == 0
	if (n_elem > 13) //ошибка: невозможно отразить такое большое число.
	{
		tmp = ft_create_elem("ERR"); //Возвращаем 1 элемент со строкой "ERR"
		res = &tmp;
		return (res);
	}
	i = 0;
	res = &tmp;
	while (i < n_elem)
	{
		ft_list_push_front(res, ft_substr(nbr, len - i * 3, 3));
		i++;
	}
	return (res);
}

char	*convert(char	*nbr, char	*dic)
{
	char	*res;
	char	*tmp;
	t_list	**triplets; //указатель на стек.
	t_btree	*dict; //пусть будет двоичное дерево.

	tmp = check_nbr(nbr); //возвращает строку без ведущих +- либо NULL, если некорректноая строка.
	if (tmp == NULL) //ошибка - на входе не целое положительное число.
		return ("Error\n");
	triplets = parse_nbr(tmp); //принимает на вход строку, возвращает список триплетов, сортированный по 10^3 по убыванию.
	if (ft_list_find(*triplets, "ERR", ft_strcmp)) //ошибка парсера - число больше 10^39 - 1
		return ("Dict Error\n");

	dict = parse_dict(dic); //принимает на вход имя файла, возвращает дерево кортежей ключ-значение.
	if (dict == NULL) //ошибка - не удалось распарсить словарь, либо словарь не позволяет разрешить введенное число.
		return ("Dict Error\n"); //ошибка словаря если нам подсунули тот, в котором не хватает ключей до полного дефолтного набора.
	res = lookup(triplets); //принимает на вход список триплетов, сортированный по 10^3 по убыванию, возвращает строку, являющуюся конкатенацией прописей триплетов и прописей соответствующих степеней 10.
	ft_list_clear(&triplets); //чистим память
	btree_clear(&dict); //чистим память
	return (res); //возвращаем результирующую строку
}

int	main(int	argc, char	**argv)
{
	if (argc == 2)
		ft_putstr(convert(argv[1], "numbers.dict"));
	if (argc == 3)
		ft_putstr(convert(argv[2], argv[1]));
	return (0);
}
