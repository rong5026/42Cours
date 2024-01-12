/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:45:06 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/19 00:47:05 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	end_philo(t_monitor *monitor)
{
	end_thread(monitor);
	kill_process(monitor);
	malloc_free(monitor);
	free_monitor(monitor);
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
	int i;
	int	ret;

	i = 0;
	while (i < monitor->philo_num)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < monitor->philo_num)
				kill(monitor->philo[i].pid, SIGTERM);
			break ;
		}
		i++;
	}
}

void	free_monitor(t_monitor *monitor)
{
	sem_close(monitor->sem_finish_type);
	sem_close(monitor->sem_print);
	sem_close(monitor->fork);
	sem_close(monitor->sem_cnt_eat);
	sem_close(monitor->sem_last_eat);
	sem_unlink("sem_finish_type");
	sem_unlink("sem_print");
	sem_unlink("sem_fork");
	sem_unlink("sem_cnt_eat");
	sem_unlink("sem_last_eat");
}

void	malloc_free(t_monitor *monitor)
{
	if (monitor->philo)
		free(monitor->philo);
}
