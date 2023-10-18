/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:13:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 18:28:08 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*monitor_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (get_die(philo->monitor) == ALIVE)
	{
		if (start_death_check(philo))
			return (0);
	}
	return (0);
}

int	start_death_check(t_philo *philo)
{
	sem_wait(philo->monitor->sem_must_eat);
	if (philo->monitor->must_eat_num != -1)
	{
		sem_post(philo->monitor->sem_must_eat);
		while (get_die(philo->monitor) == ALIVE)
		{
			if (starving_death(philo))
				return (1);
			if (full_eat_death(philo))
				return (1);
		}
	}
	else
	{
		sem_post(philo->monitor->sem_must_eat);
		while (get_die(philo->monitor) == ALIVE)
		{
			if (starving_death(philo))
				return (1);
		}
	}
	return (1);
}

int	starving_death(t_philo *philo)
{
	if (get_die(philo->monitor) == ALIVE)
	{
		sem_wait(philo->sem_last_eat);
		sem_wait(philo->monitor->sem_time_die);
		if ((get_time() - philo->last_eat) > (size_t)(philo->monitor->time_to_die))
		{
			sem_wait(philo->monitor->sem_finish_type);
			philo->monitor->finish_type = DIE;
			sem_post(philo->monitor->sem_finish_type);
			print_finish_state(philo);
			sem_post(philo->sem_last_eat);
			sem_post(philo->monitor->sem_time_die);
			return (1);
		}
		sem_post(philo->sem_last_eat);
		sem_post(philo->monitor->sem_time_die);
	}
	return (0);
}

int	full_eat_death(t_philo *philo)
{
	sem_wait(philo->monitor->sem_must_eat);
	if (philo->monitor->must_eat_num != -1)
	{
		sem_wait(philo->sem_cnt_eat);
		if (philo->cnt_eat >= philo->monitor->must_eat_num)
		{
			sem_wait(philo->monitor->sem_finish_type);
			philo->monitor->finish_type = FULL;
			sem_post(philo->monitor->sem_finish_type);
			sem_post(philo->sem_cnt_eat);
			sem_post(philo->monitor->sem_must_eat);
			return (1);
		}
		sem_post(philo->sem_cnt_eat);
	}
	sem_post(philo->monitor->sem_must_eat);
	return (0);
}
