/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:24:19 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/08/14 12:15:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	end_philo(t_game *game)
{
	end_thread(game);
	unlock_and_destroy(game);
	malloc_free(game);
}

void	end_thread(t_game *game)
{
	int	philo;
	int	i;

	i = 0;
	philo = game->philo_num;
	while (i < philo)
	{
		pthread_join(game->philo[i].thread_id, NULL);
		i++;
	}
}

void	unlock_and_destroy(t_game *game)
{
	int	philo;
	int	i;

	i = 0;
	philo = game->philo_num;
	while (i < philo)
	{
		pthread_mutex_unlock(&game->fork[i]);
		pthread_mutex_destroy(&game->fork[i]);
		i++;
	}
	pthread_mutex_unlock(&game->printing);
	pthread_mutex_destroy(&game->printing);
	pthread_mutex_unlock(&game->eating);
	pthread_mutex_destroy(&game->eating);
	pthread_mutex_unlock(&game->die_mutex);
	pthread_mutex_destroy(&game->die_mutex);
	pthread_mutex_unlock(&game->philo_eat);
	pthread_mutex_destroy(&game->philo_eat);
	pthread_mutex_unlock(&game->philo_alive);
	pthread_mutex_destroy(&game->philo_alive);
}

void	malloc_free(t_game *game)
{
	if (game->philo)
		free(game->philo);
	if (game->fork)
		free(game->fork);
}
