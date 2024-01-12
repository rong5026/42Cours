/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:25:27 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/19 00:43:28 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	eat_or_sleep_time(long do_time)
{
	size_t	time;

	time = get_time();
	usleep(do_time * 920);
	while (get_time() < time + do_time)
		usleep(do_time * 3);
}

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
			return (-1);
		i++;
	}
	return ((int)(sign * result));
}
