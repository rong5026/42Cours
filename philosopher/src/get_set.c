/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:46:54 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/08/14 00:55:01 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_die(t_game *game)
{
	int sign;

	pthread_mutex_lock(&game->die_mutex);
	sign = game->die;
	pthread_mutex_unlock(&game->die_mutex);
	return (sign);
}

void	set_die(t_game *game, int sign)
{
	pthread_mutex_lock(&game->die_mutex);
	game->die = sign;
	pthread_mutex_unlock(&game->die_mutex);
}

int get_alive(t_game *game, t_philo *philo)
{
    int sign;

	pthread_mutex_lock(&game->philo_alive);
	sign = philo->alive;
	pthread_mutex_unlock(&game->philo_alive);
	return (sign);
}

void	set_alive(t_game *game, t_philo *philo, int sign)
{
	pthread_mutex_lock(&game->philo_alive);
	philo->alive = sign;
	pthread_mutex_unlock(&game->philo_alive);
}
