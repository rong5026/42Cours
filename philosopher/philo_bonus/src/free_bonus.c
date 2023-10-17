/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:45:06 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:16:59 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	kill_process(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->philo_num)
	{
		if (monitor->philo[i].pid > 0)
			kill(monitor->philo[i].pid, SIGTERM);
		else
			break ;
		i++;
	}
	free(monitor->philo);
}

void	free_monitor(void)
{
	sem_unlink("sem_start");
	sem_unlink("sem_finish");
	sem_unlink("sem_print");
	sem_unlink("sem_fork");
	sem_unlink("sem_full");
}
