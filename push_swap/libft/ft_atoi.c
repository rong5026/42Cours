/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:16:18 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:56 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char ch)
{
	if (ch == '\t')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\v')
		return (1);
	if (ch == '\f')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == ' ')
		return (1);
	return (0);
}

int	check_integer_atoi(long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	else
		return (1);
}

long	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && is_space(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (!check_integer_atoi(result * sign))
			return (result * sign);
		i++;
	}
	return ((int)(sign * result));
}
