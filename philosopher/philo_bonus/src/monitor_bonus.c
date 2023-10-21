/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:13:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/19 10:31:47 by hong-yeongh      ###   ########.fr       */
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
	
	if (philo->monitor->must_eat_num != -1)
	{
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
		sem_wait(philo->monitor->sem_last_eat);
		if ((get_time() - philo->last_eat) > (size_t)(philo->monitor->time_to_die))
		{
			// sem_wait(philo->monitor->sem_finish_type);
			// philo->monitor->finish_type = DIE;
			// sem_post(philo->monitor->sem_finish_type);
			print_finish_state(philo);
			sem_wait(philo->monitor->sem_print); // 죽고나서 출력 막기
			exit(1);
		}
		sem_post(philo->monitor->sem_last_eat);
	}
	return (0);
}

int	full_eat_death(t_philo *philo)
{
	if (philo->monitor->must_eat_num != -1)
	{
		sem_wait(philo->monitor->sem_cnt_eat);
		if (philo->cnt_eat >= philo->monitor->must_eat_num)
		{
			// sem_wait(philo->monitor->sem_finish_type);
			// philo->monitor->finish_type = FULL;
			// sem_post(philo->monitor->sem_finish_type);
			sem_wait(philo->monitor->sem_print); // 죽고나서 출력 막기
			exit(1);
		}
		sem_post(philo->monitor->sem_cnt_eat);
	}
	return (0);
}
