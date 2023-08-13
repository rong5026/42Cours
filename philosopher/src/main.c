/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:31:56 by yeohong	       #+#    #+#             */
/*   Updated: 2023/08/12 15:06:08 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	reak_check(void)
{
	system("leaks philo");
}

int	init_set(t_game *game)
{
	if(init_mutex(game))
	{
		unlock_and_destroy(game);
		malloc_free(game);
	}
	if(init_philosopher(game))
	{
		unlock_and_destroy(game);
		malloc_free(game);
	}
    return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	atexit(reak_check);
	if (check_first_valid(ac, av))
		return (1);
	init_input(&game, ac, av);
	if (check_second_valid(&game, ac))
		return (1);
	if (init_set(&game))
		return (1);
	start_philo(&game, (&game)->philo);
	return (0);
}

