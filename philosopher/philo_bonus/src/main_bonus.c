/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:02 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 18:30:48 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	start_philo(t_monitor *monitor)
{
	int	i;

	i = 0;
	monitor->start_time = get_time();
	while (i < monitor->philo_num)
	{
		monitor->philo[i].pid = fork();
		if (monitor->philo[i].pid < 0)
			return (1);
		if (monitor->philo[i].pid == 0)
			run_philo(monitor, i);
		i++;
	}
	end_philo(monitor);
	printf("asdfasdfasdfasdf");
	return (0);
}

int	main(int ac, char **av)
{
	t_monitor	monitor;

	if (check_first_valid(ac, av))
		return (1);
	init_input(&monitor, ac, av);
	if (check_second_valid(&monitor, ac))
		return (1);
	if (init_set(&monitor))
		return (1);
	start_philo(&monitor);
	return (0);
}
