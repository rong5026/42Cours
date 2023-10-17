/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:51:09 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:20:52 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	init_monitor(t_monitor *monitor, int ac, char **av)
{
	monitor->philo_num = ft_atoi(av[1]);
	monitor->time_to_die = ft_atoi(av[2]);
	monitor->time_to_eat = ft_atoi(av[3]);
	monitor->time_to_sleep = ft_atoi(av[4]);
	monitor->must_eat_flag = 0;
	monitor->full_cnt = 0;
	monitor->finish_type = 0;
	if (ac == 6)
	{
		monitor->must_eat_num = ft_atoi(av[5]);
		monitor->must_eat_flag = 1;
	}
}

int	init_set(t_monitor *monitor)
{
	if (init_sem(monitor))
		return (1);
	if (init_philosopher(monitor))
	{
		sem_wait(monitor->sem_print);
		printf("fail in generating philosophers\n");
		sem_post(monitor->sem_finish);
		return (1);
	}
	return (0);
}

int	init_sem(t_monitor *monitor)
{
	monitor->philo = malloc(sizeof(t_philo) * monitor->philo_num);
	if (monitor->philo == NULL)
		return (1);
	sem_unlink("sem_start");
	monitor->sem_start = sem_open("sem_start", O_CREAT, 0644, 1);
	sem_unlink("sem_finish");
	monitor->sem_finish = sem_open("sem_finish", O_CREAT, 0644, 0);
	sem_unlink("sem_print");
	monitor->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	sem_unlink("sem_fork");
	monitor->fork = sem_open("sem_fork", O_CREAT, 0644, monitor->philo_num);
	sem_unlink("sem_full");
	monitor->sem_full = sem_open("sem_full", O_CREAT, 0644, 0);
	return (0);
}

int	init_philosopher(t_monitor *monitor)
{
	int	i;

	sem_wait(monitor->sem_start);
	i = 0;
	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (1);
	while (i < monitor->philo_num)
	{
		monitor->philo[i].pid = fork();
		if (monitor->philo[i].pid < 0)
			break ;
		if (monitor->philo[i].pid == 0)
		{
			start(monitor, i);
			return (0);
		}
		i++;
	}
	sem_post(monitor->sem_start);
	return (0);
}

void	set_philo(t_monitor *monitor, t_philo *philo, int i)
{
	philo->id = i;
	philo->last_eat = 0;
	philo->cnt_eat = 0;
	philo->monitor = monitor;
	sem_unlink("sem_last_eat");
	philo->sem_last_eat = sem_open("sem_last_eat", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_last_eat");
	sem_unlink("sem_cnt_eat");
	philo->sem_cnt_eat = sem_open("sem_cnt_eat", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_cnt_eat");
}
