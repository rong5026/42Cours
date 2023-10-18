/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:07:12 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 23:19:56 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	get_die(t_monitor *monitor)
{
	int	sign;

	sem_wait(monitor->sem_finish_type);
	sign = monitor->finish_type;
	sem_post(monitor->sem_finish_type);
	return (sign);
}

size_t	get_time(void)
{
	struct timeval	current;
	size_t			result;

	gettimeofday(&current, NULL);
	result = (size_t)(current.tv_sec * 1000) + (size_t)(current.tv_usec / 1000);
	return (result);
}
