/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:08:32 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 18:19:41 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	run_philo(t_monitor *monitor, int i)
{
	if (pthread_create(&monitor->philo[i].death_check, NULL, monitor_philo, \
										&(monitor->philo[i])) != 0)
		sem_print("fail in create sub_monitor", monitor);
	sem_wait(monitor->philo[i].sem_last_eat);
	monitor->philo[i].last_eat = get_time();
	sem_post(monitor->philo[i].sem_last_eat);
	if (monitor->philo[i].id % 2 == 1)
		usleep(1000);
	while (get_die(monitor) == ALIVE)
	{
		if (run_take_fork(&(monitor->philo[i])))
			return ;
		if (run_eat(&(monitor->philo[i])))
			return ;
		if (run_takeoff_fork(&(monitor->philo[i])))
			return ;
		if (run_sleep(&(monitor->philo[i])))
			return ;
		if (print_think_state(&(monitor->philo[i])))
			return ;
	}
}

int	run_take_fork(t_philo *philo)
{
	if (get_die(philo->monitor) != ALIVE)
		return (1);
	sem_wait(philo->monitor->fork);
	print_take_fork_state(philo);
	sem_wait(philo->monitor->fork);
	print_take_fork_state(philo);
	return (0);
}

int	run_takeoff_fork(t_philo *philo)
{
	if (get_die(philo->monitor) != ALIVE)
		return (1);
	sem_post(philo->monitor->fork);
	sem_post(philo->monitor->fork);
	return (0);
}

int	run_eat(t_philo *philo)
{
	if (get_die(philo->monitor) != ALIVE)
		return (1);
	sem_wait(philo->sem_last_eat);
	philo->last_eat = get_time();
	sem_post(philo->sem_last_eat);
	print_eat_state(philo);
	sem_wait(philo->monitor->sem_time_eat);
	eat_or_sleep_time(philo->monitor->time_to_eat);
	sem_post(philo->monitor->sem_time_eat);
	sem_wait(philo->sem_cnt_eat);
	(philo->cnt_eat)++;
	sem_post(philo->sem_cnt_eat);
	return (0);
}

int	run_sleep(t_philo *philo)
{
	if (get_die(philo->monitor) != ALIVE)
		return (1);
	print_sleep_state(philo);
	sem_wait(philo->monitor->sem_time_sleep);
	eat_or_sleep_time(philo->monitor->time_to_sleep);
	sem_post(philo->monitor->sem_time_sleep);
	return (0);
}
