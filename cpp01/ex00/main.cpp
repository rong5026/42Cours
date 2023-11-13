/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:59 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 17:31:33 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name;

    std::cout << "Stack Zombie name: " << std::flush;
    std::cin >> name;
	
	randomChump(name);

    std::cout << "Heap Zombie name: " << std::flush;
    std::cin >> name;
	
	Zombie *zombi2 = newZombie(name);
	zombi2->announce();
	delete zombi2;

	return (0);
}
