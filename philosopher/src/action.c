/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:30:28 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/13 20:43:47 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo, t_game *game)
{	
	if (philo->alive == 1)
		return (1);
	if (game->philo_num == 1)
	{
		pthread_mutex_lock(&game->fork[philo->left_fork]);
		print_time("has taken a fork", game, philo);
		one_philo_time(game);
		pthread_mutex_unlock(&game->fork[philo->left_fork]);
		return (check_die_elem(game));
	}
	pthread_mutex_lock(&game->fork[philo->left_fork]);
	print_time("has taken a fork", game, philo);
	pthread_mutex_lock(&game->fork[philo->right_fork]);
	print_time("has taken a fork", game, philo);
	if (check_die_elem(game) == 1)
	{
		pthread_mutex_unlock(&game->fork[philo->left_fork]);
		pthread_mutex_unlock(&game->fork[philo->right_fork]);
		return (1);
	}
	return (0);
}

int	take_eat(t_philo *philo, t_game *game)
{
	if (philo->alive == 1)
	{
		pthread_mutex_unlock(&game->fork[philo->left_fork]);
		pthread_mutex_unlock(&game->fork[philo->right_fork]);
		return (1);
	}
	philo->last_eat_time = get_time();
	philo->eat_cnt++;
	print_time("is eating", game, philo);
	eat_or_sleep_time(game, game->time_to_eat);
	pthread_mutex_unlock(&game->fork[philo->left_fork]);
	pthread_mutex_unlock(&game->fork[philo->right_fork]);
	return (check_die_elem(game));
}

int	take_sleep(t_philo *philo, t_game *game)
{
	if (philo->alive == 1)
		return (1);
	print_time("is sleeping", game, philo);
	eat_or_sleep_time(game, game->time_to_sleep);
	return (check_die_elem(game));
}

int	take_think(t_philo *philo, t_game *game)
{
	if (philo->alive == 1)
		return (1);
	print_time("is thinking", game, philo);
	return (check_die_elem(game));
}

int	check_die_elem(t_game *game)
{
	if (game->die == 1)
		return (1);
	return (0);
}
