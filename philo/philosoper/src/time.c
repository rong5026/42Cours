/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:33:31 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/14 12:15:54 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	current;
	size_t			result;

	gettimeofday(&current, NULL);
	result = (size_t)(current.tv_sec * 1000) + (size_t)(current.tv_usec / 1000);
	return (result);
}

void	eat_or_sleep_time(size_t do_time)
{
	size_t	time;

	time = get_time();
	usleep(do_time * 920);
	while (get_time() < time + do_time)
		usleep(do_time * 3);
}

void	one_philo_time(t_game *game)
{
	size_t	standard_time;

	standard_time = get_time();
	while (get_die(game) != 1)
	{
		if (get_time() - standard_time >= (size_t)(game->time_to_die + 2000))
			return ;
		usleep(10);
	}
}
