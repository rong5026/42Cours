/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:23:40 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/19 00:47:05 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	print_take_fork_state(t_philo *philo)
{
	long			time_stamp;

	sem_wait(philo->monitor->sem_print);
	time_stamp = get_time() - philo->monitor->start_time;
	printf("%ldms\t%d\thas taken a fork\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_eat_state(t_philo *philo)
{
	long			time_stamp;

	sem_wait(philo->monitor->sem_print);
	time_stamp = get_time() - philo->monitor->start_time;
	printf("%ldms\t%d\tis eating\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_sleep_state(t_philo *philo)
{
	long			time_stamp;

	sem_wait(philo->monitor->sem_print);
	time_stamp = get_time() - philo->monitor->start_time;
	printf("%ldms\t%d\tis sleeping\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_think_state(t_philo *philo)
{
	long			time_stamp;

	if (get_die(philo->monitor) != ALIVE)
		return (1);
	sem_wait(philo->monitor->sem_print);
	time_stamp = get_time() - philo->monitor->start_time;
	printf("%ldms\t%d\tis thinking\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_finish_state(t_philo *philo)
{
	long			time_stamp;

	sem_wait(philo->monitor->sem_print);
	time_stamp = get_time() - philo->monitor->start_time;
	printf("%ldms\t%d\tis died\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (1);
}
