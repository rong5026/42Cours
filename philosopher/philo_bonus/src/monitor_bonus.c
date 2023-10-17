/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:13:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:50:37 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*monitor_philo(void *arg)
{
	t_philo	*philo;
	int		dup_flag;

	philo = arg;
	dup_flag = 0;
	while (1)
	{
		if (check_die(philo))
		{
			print_finish_state(philo);
			philo->monitor->finish_type = DIE;
			sem_post(philo->monitor->sem_finish);
		}
		if (!dup_flag && philo->monitor->must_eat_flag)
		{
			sem_wait(philo->sem_cnt_eat);
			if (philo->cnt_eat >= philo->monitor->must_eat_num)
			{
				sem_post(philo->monitor->sem_full);
				dup_flag = 1;
			}
			sem_post(philo->sem_cnt_eat);
		}
	}
	return (0);
}

int	check_die(t_philo *philo)
{
	struct timeval	curr_time;
	long			time_gap;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		sem_print("fail in gettimeofday", philo->monitor);
		return (1);
	}
	sem_wait(philo->sem_last_eat);
	time_gap = get_time() - philo->last_eat;
	sem_post(philo->sem_last_eat);
	if (time_gap > philo->monitor->time_to_die)
		return (1);
	return (0);
}

int	monitor_main(t_monitor *monitor)
{
	pthread_t	sub_monitor;
	int			i;

	if (pthread_create(&sub_monitor, NULL, monitor_full, monitor) != 0)
		sem_print("fail in create in main", monitor);
	sem_wait(monitor->sem_finish);
	kill_process(monitor);
	monitor->finish_type = DIE;
	i = 0;
	while (i < monitor->philo_num)
	{
		sem_post(monitor->sem_full);
		i++;
	}
	pthread_join(sub_monitor, NULL);
	free_monitor();
	return (0);
}

void	*monitor_full(void *arg)
{
	t_monitor		*monitor;
	int				i;
	long			time_stamp;
	struct timeval	curr_time;

	monitor = arg;
	i = 0;
	while (i < monitor->philo_num)
	{
		sem_wait(monitor->sem_full);
		i++;
	}
	if (monitor->finish_type != DIE)
	{
		sem_wait(monitor->sem_print);
		if (gettimeofday(&(curr_time), NULL) != 0)
		{
			sem_print("fail in gettimeofday", monitor);
			return (0);
		}
		time_stamp = get_time();
		printf("%ldms\tall philosophers are full\n", time_stamp);
		sem_post(monitor->sem_finish);
	}
	return (0);
}
