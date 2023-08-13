/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:26:38 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/13 16:19:38 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_philo(t_game *game, t_philo *philo)
{
	int		i;

	i = 0;
	game->start_time = get_time();
	while (i < game->philo_num)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&philo[i].thread_id, NULL, run_thread, (void *)&(philo[i])))
			return (1);
		i++;
	}
	start_death_check(game);
	end_philo(game);
	return (0);
}

void	*run_thread(void *philo)
{
	t_philo	*philo_tmp;

	
	philo_tmp = (t_philo *)philo;
	if (philo_tmp->id % 2)
			usleep(10000);
	while (philo_tmp->game->die != 1)
	{
		if(take_fork(philo_tmp, philo_tmp->game))
			return (0);
		if(take_eat(philo_tmp, philo_tmp->game))
			return (0);
		if(take_sleep(philo_tmp, philo_tmp->game))
			return (0);
		if(take_think(philo_tmp, philo_tmp->game))
			return (0);
	}
	return (0);
}

void	start_death_check(t_game *game)
{
	while (game->die != 1)
	{
		starving_death(game);
		full_eat_death(game);
	}
}

void	starving_death(t_game *game)
{
	int i;
	t_philo *philo;

	philo = game->philo;
	i = 0;
	while (game->die != 1 && i < game->philo_num)
	{
		pthread_mutex_lock(&game->eating);
		if ((get_time() - philo[i].last_eat_time) > (size_t)(game->time_to_die))
		{
			print_time("died", game, philo);
			game->die = 1;
		}
		pthread_mutex_unlock(&game->eating);
		i++;
	}
}

void	full_eat_death(t_game *game)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	if (game->must_eat_num != -1)
	{
		while (i < game->philo_num)
		{
			if (game->philo[i].eat_cnt >= game->must_eat_num)
				cnt++;
			i++;
		}
		if (cnt == game->philo_num) 
		{
			game->die = 1;
		}
	}
}
