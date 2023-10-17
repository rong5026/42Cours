/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:46:02 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:17:07 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int ac, char **av)
{
	t_monitor	monitor;

	if (check_first_valid(ac, av))
		return (1);
	init_monitor(&monitor, ac, av);
	if (check_second_valid(&monitor, ac))
		return (1);
	if (init_set(&monitor))
		return (1);
	monitor_main(&monitor);
	return (0);
}
