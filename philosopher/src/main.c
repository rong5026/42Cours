/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:31:56 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/08/12 14:53:32 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_set(t_game *game)
{
    if (init_mutex(&game))
        return (1);
    if (init_philosopher(&game))
        reutnr (1);
    // 위에 리턴하기전에 오류문구 +  메모리 해제 
}
int main(int ac, char **av)
{
    t_game game;
    
    if (check_first_valid(ac, av))
        return (1);
    init_input(&game, ac, av);
    if (check_second_valid(&game, ac))
        return (1);
    init_set(&game);
        
    return (0);
}