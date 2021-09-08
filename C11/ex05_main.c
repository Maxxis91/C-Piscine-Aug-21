#include <unistd.h>

typedef long (*t_func)(int, int);

int ft_isspace(char c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    else
        return (0);
}

int ft_atoi(char    *str)
{
    int res;
    int sign;

    res = 0;
    sign = 1;
    while (*str && ft_isspace(*str))
        str++;
    while (*str && (*str == '+' || *str == '-'))
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str && (*str >= 48 && *str <= 57))
    {
        res = res * 10 + *str - 48;
        str++;
    }
    res *= sign;
    return (res);
}

void    ft_putnbr(int   nb)
{
    char    c;

    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else
    {
        if (nb >= 0 && nb <= 9)
        {
            c = nb + '0';
            write(1, &c, 1);
        }
        if (nb < 0)
        {
            write (1, "-", 1);
            ft_putnbr(-nb);
        }
        if (nb > 9)
        {
            ft_putnbr(nb / 10);
            ft_putnbr(nb % 10);
        }
    }
}

long ft_add(int a, int b)
{
  return (long)(a + b);
}

long ft_sub(int a, int b)
{
  return (long)(a - b);
}

long ft_mul(int a, int b)
{
  return (long)(a * b);
}

long ft_div(int a, int b)
{
    return (long)(a / b);
}

long ft_mod(int a, int b)
{
    return (long)(a % b);
}

void    ft_arr_func(t_func *ops)
{
    ops[0] = &ft_add;
    ops[1] = &ft_sub;
    ops[2] = &ft_mul;
    ops[3] = &ft_div;
    ops[4] = &ft_mod;
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;
	int	res;

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

int	is_op(char *str)
{
	if (ft_strcmp(str, "+") == 0)
		return (0);
	if (ft_strcmp(str, "-") == 0)
		return (1);
	if (ft_strcmp(str, "*") == 0)
		return (2);
	if (ft_strcmp(str, "/") == 0)
		return (3);
	if (ft_strcmp(str, "%") == 0)
		return (4);
	return (-1);
}

int main (int   argc, char  **argv)
{
    int	op;
    int	res;
	t_func ops[5];

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
	res = ops[op](ft_atoi(argv[1]),ft_atoi(argv[3]));
	ft_putnbr(res);
	write(1, "\n", 1);
    return (0);
}
