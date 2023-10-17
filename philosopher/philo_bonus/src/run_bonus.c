/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:08:32 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:20:45 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	start(t_monitor *monitor, int i)
{
	pthread_t	sub_monitor;

	set_philo(monitor, &(monitor->philo[i]), i);
	sem_wait(monitor->sem_start);
	sem_post(monitor->sem_start);
	if (pthread_create(&sub_monitor, NULL, monitor_philo, \
										&(monitor->philo[i])) != 0)
		sem_print("fail in create sub_monitor in philo", monitor);
	if (monitor->philo[i].id % 2 == 1)
		usleep(monitor->time_to_eat / 2 * 1e3);
	while (1)
	{
		run_take_fork(&(monitor->philo[i]));
		run_eat(&(monitor->philo[i]));
		run_takeoff_fork(&(monitor->philo[i]));
		run_sleep(&(monitor->philo[i]));
		print_think_state(&(monitor->philo[i]));
		usleep(50);
	}
}

void	run_takeoff_fork(t_philo *philo)
{
	sem_post(philo->monitor->fork);
	sem_post(philo->monitor->fork);
	return ;
}

void	run_take_fork(t_philo *philo)
{
	sem_wait(philo->monitor->fork);
	print_take_fork_state(philo);
	sem_wait(philo->monitor->fork);
	print_take_fork_state(philo);
}

void	run_eat(t_philo *philo)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		sem_print("fail in gettimeofday", philo->monitor);
		return ;
	}
	sem_wait(philo->sem_last_eat);
	philo->last_eat = calc_timeval(&(philo->monitor->start_time), &curr_time);
	sem_post(philo->sem_last_eat);
	print_eat_state(philo);
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 200);
	sem_wait(philo->sem_cnt_eat);
	(philo->cnt_eat)++;
	sem_post(philo->sem_cnt_eat);
}

void	run_sleep(t_philo *philo)
{
	struct timeval	start_time;

	print_sleep_state(philo);
	if (gettimeofday(&(start_time), NULL) != 0)
	{
		sem_print("fail in gettimeofday", philo->monitor);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 200);
}
