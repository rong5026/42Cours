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

int	init_set(t_game *game)
{
	// 위에 리턴하기전에 오류문구 +  메모리 해제 
	init_mutex(game);
	init_philosopher(game);
	
    return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (check_first_valid(ac, av))
		return (1);
	init_input(&game, ac, av);
	if (check_second_valid(&game, ac))
		return (1);
	init_set(&game);
	start_philo(&game, (&game)->philo);
	return (0);
}

