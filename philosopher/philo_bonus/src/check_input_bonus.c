/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:48:30 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/19 00:47:05 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	check_first_valid(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		printf("Invalid Input Count\n");
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (!is_digit(av[i]))
		{
			printf("Argument must be a number\n");
			return (1);
		}
		if (ft_atoi(av[i]) < 0)
		{
			printf("Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_second_valid(t_monitor *monitor, int ac)
{
	if (monitor->philo_num < 1)
	{
		printf("Invalid Input\n");
		return (1);
	}
	if (ac == 6)
	{
		if (monitor->must_eat_num < 0)
		{
			printf("Invalid Input\n");
			return (1);
		}
		else if (monitor->must_eat_num == 0)
			return (1);
	}
	return (0);
}
