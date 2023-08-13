/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:33:31 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/13 15:32:07 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

void	eat_or_sleep_time(t_game *game, size_t do_time)
{
	size_t	standard_time;

	standard_time = get_time();
	while (game->die != 1)
	{
		if (get_time() - standard_time >= do_time)
			return ;
		usleep(10);
	}
}
