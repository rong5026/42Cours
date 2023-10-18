/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:45:06 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 17:57:14 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	end_philo(t_monitor *monitor)
{
	end_thread(monitor);
	kill_process(monitor);
	malloc_free(monitor);
	free_monitor();
}

void	end_thread(t_monitor *monitor)
{
	int	philo;
	int	i;

	i = 0;
	philo = monitor->philo_num;
	while (i < philo)
	{
		pthread_join(monitor->philo[i].death_check, NULL);
		i++;
	}
}

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
}

void	free_monitor(void)
{
	sem_unlink("sem_start");
	sem_unlink("sem_time_die");
	sem_unlink("sem_finish_type");
	sem_unlink("sem_must_eat");
	sem_unlink("sem_print");
	sem_unlink("sem_fork");
	sem_unlink("sem_last_eat");
	sem_unlink("sem_cnt_eat");
	sem_unlink("sem_time_eat");
	sem_unlink("sem_time_sleep");
}

void	malloc_free(t_monitor *monitor)
{
	if (monitor->philo)
		free(monitor->philo);
}
