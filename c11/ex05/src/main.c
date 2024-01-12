/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:06:02 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/18 14:32:40 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_atoi.h"
#include "ft_putnbr.h"
#include "ft_hong.h"

int	is_operator(char *str)
{
	if (*str == '+')
		return (1);
	else if (*str == '-')
		return (2);
	else if (*str == '*')
		return (3);
	else if (*str == '/')
		return (4);
	else if (*str == '%')
		return (5);
	return (0);
}

void	print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	calculate(int a, char *operator, int b, int (*ft[5])(int, int))
{
	if (is_operator(operator) == 1)
		return (ft[0](a, b));
	else if (is_operator(operator) == 2)
		return (ft[1](a, b));
	else if (is_operator(operator) == 3)
		return (ft[2](a, b));
	else if (is_operator(operator) == 4)
		return (ft[3](a, b));
	else
		return (ft[4](a, b));
}

int	hongssi(int b, char *operator)
{
	if (is_operator(operator) == 4 && b == 0)
	{
		print_str("Stop : division by zero");
		return (0);
	}
	else if (is_operator(operator) == 5 && b == 0)
	{
		print_str("Stop : modulo by zero");
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		(*ft[5])(int, int);
	int		result;

	ft[0] = add;
	ft[1] = sub;
	ft[2] = mul;
	ft[3] = div;
	ft[4] = mod;
	if (argc != 4)
		return (0);
	if (!is_operator(argv[2]))
		write(1, "0\n", 2);
	else
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (hongssi(b, argv[2]) == 1)
		{
			result = calculate(a, argv[2], b, ft);
			ft_putnbr(result);
			write(1, "\n", 1);
		}
	}
}
