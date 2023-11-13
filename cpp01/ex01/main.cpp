/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:59 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 14:51:47 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	size_t N;

	N = 5;
	Zombie *zombie_list = zombieHorde(N, "zombi");

    for (size_t i = 0; i < N; i++) {
        zombie_list[i].announce();
    }
	
    delete [] zombie_list;
    return 0;
}
