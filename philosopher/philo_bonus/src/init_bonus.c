/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:51:09 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 17:56:45 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	init_input(t_monitor *monitor, int ac, char **av)
{
	monitor->philo_num = ft_atoi(av[1]);
	monitor->time_to_die = ft_atoi(av[2]);
	monitor->time_to_eat = ft_atoi(av[3]);
	monitor->time_to_sleep = ft_atoi(av[4]);
	monitor->full_cnt = 0;
	monitor->finish_type = ALIVE;
	monitor->start_time = 0;
	if (ac == 6)
		monitor->must_eat_num = ft_atoi(av[5]);
	else
		monitor->must_eat_num = -1;
}

int	init_set(t_monitor *monitor)
{
	if (init_sem(monitor))
		return (1);
	if (init_philosopher(monitor))
		return (1);
	return (0);
}

int	init_philosopher(t_monitor *monitor)
{
	int	i;

	i = 0;
	monitor->philo = malloc(sizeof(t_philo) * monitor->philo_num);
	if (monitor->philo == NULL)
		return (1);
	while (i < monitor->philo_num)
	{
		monitor->philo[i].id = i;
		monitor->philo[i].last_eat = 0;
		monitor->philo[i].cnt_eat = 0;
		monitor->philo[i].monitor = monitor;
		sem_unlink("sem_last_eat");
		monitor->philo[i].sem_last_eat = sem_open("sem_last_eat", O_CREAT | O_EXCL, 0644, 1);
		sem_unlink("sem_cnt_eat");
		monitor->philo[i].sem_cnt_eat = sem_open("sem_cnt_eat", O_CREAT | O_EXCL, 0644, 1);
		i++;
	}
	return (0);
}

int	init_sem(t_monitor *monitor)
{
	sem_unlink("sem_start");
	monitor->sem_start = sem_open("sem_start", O_CREAT, 0644, 1);
	sem_unlink("sem_time_sleep");
	monitor->sem_time_sleep = sem_open("sem_time_sleep", O_CREAT, 0644, 1);
	sem_unlink("sem_time_eat");
	monitor->sem_time_eat = sem_open("sem_time_eat", O_CREAT, 0644, 1);
	sem_unlink("sem_time_die");
	monitor->sem_time_die = sem_open("sem_time_die", O_CREAT, 0644, 1);
	sem_unlink("sem_finish_type");
	monitor->sem_finish_type = sem_open("sem_finish_type", O_CREAT, 0644, 1);
	sem_unlink("sem_must_eat");
	monitor->sem_must_eat = sem_open("sem_must_eat", O_CREAT, 0644, 1);
	sem_unlink("sem_print");
	monitor->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	sem_unlink("sem_fork");
	monitor->fork = sem_open("sem_fork", O_CREAT, 0644, monitor->philo_num);
	return (0);
}
