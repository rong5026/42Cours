/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:30:28 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/13 01:16:02 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo, t_game *game)
{
	pthread_mutex_lock(&game->fork[philo->left_fork]);
	print_time("has taken a fork", game, philo);
	pthread_mutex_lock(&game->fork[philo->right_fork]);
	print_time("has taken a fork", game, philo);
}

void	take_eat(t_philo *philo, t_game *game)
{
	
	philo->eat_cnt++;
	pthread_mutex_lock(&game->eating);
	print_time("is eating", game, philo);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&game->eating);
	eat_or_sleep_time(game, game->time_to_eat);
	pthread_mutex_unlock(&game->fork[philo->left_fork]);
	pthread_mutex_unlock(&game->fork[philo->right_fork]);	
}

void	take_sleep(t_philo *philo, t_game *game)
{
	print_time("is sleeping", game, philo);
	eat_or_sleep_time(game, game->time_to_sleep);
}

void	take_think(t_philo *philo, t_game *game)
{
	print_time("is thinking", game, philo);
}
