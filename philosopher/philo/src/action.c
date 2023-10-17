/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:30:28 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/14 12:09:17 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo, t_game *game)
{	
	if (get_alive(game, philo) == 1 || get_die(game) == 1)
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
	if (get_alive(game, philo) == 1 || get_die(game) == 1)
	{
		pthread_mutex_unlock(&game->fork[philo->left_fork]);
		pthread_mutex_unlock(&game->fork[philo->right_fork]);
		return (1);
	}
	print_time("is eating", game, philo);
	pthread_mutex_lock(&game->philo_eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(&game->philo_eat);
	pthread_mutex_lock(&game->eating);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&game->eating);
	eat_or_sleep_time(game->time_to_eat);
	pthread_mutex_unlock(&game->fork[philo->left_fork]);
	pthread_mutex_unlock(&game->fork[philo->right_fork]);
	return (check_die_elem(game));
}

int	take_sleep(t_philo *philo, t_game *game)
{
	if (get_alive(game, philo) == 1 || get_die(game) == 1)
		return (1);
	print_time("is sleeping", game, philo);
	eat_or_sleep_time(game->time_to_sleep);
	return (check_die_elem(game));
}

int	take_think(t_philo *philo, t_game *game)
{
	if (get_alive(game, philo) == 1 || get_die(game) == 1)
		return (1);
	print_time("is thinking", game, philo);
	return (check_die_elem(game));
}

int	check_die_elem(t_game *game)
{
	if (get_die(game) == 1)
		return (1);
	return (0);
}
