/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:18:51 by yeohong	       #+#    #+#             */
/*   Updated: 2023/08/12 15:06:08 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_input(t_game *game, int ac, char **av)
{
	game->philo_num = ft_atoi(av[1]);
	game->time_to_die = ft_atoi(av[2]);
	game->time_to_eat = ft_atoi(av[3]);
	game->time_to_sleep = ft_atoi(av[4]);
    game->die = 0;
	game->must_eat_num = 0;
	game->start_time = 0;
	if (ac == 6)
		game->must_eat_num = ft_atoi(av[5]);
	else
		game->must_eat_num = -1;
}

int	init_mutex(t_game *game)
{
	int	i;

	game->fork = malloc(sizeof(pthread_mutex_t) * game->philo_num);
	if (!game->fork)
		return (1);
	i = 0;
	while (i < game->philo_num)
	{
		if (pthread_mutex_init(&(game->fork[i]), NULL))
			return (1);
		i++;
	}
	pthread_mutex_init(&(game->printing), NULL);
	pthread_mutex_init(&(game->eating), NULL);
	return (0);
}

int	init_philosopher(t_game *game)
{
	int	i;

	i = 0;
	game->philo = malloc(sizeof(t_game) * game->philo_num);
	if (!game->philo)
		return (1);
	while (i < game->philo_num)
	{
		game->philo[i].id = i;
		game->philo[i].last_eat_time = 0;
		game->philo[i].eat_cnt = 0;
		game->philo[i].game = game;
		game->philo[i].left_fork = i;
		game->philo[i].right_fork = (i + 1) % game->philo_num;
		i++;
	}
	return (0);
}

