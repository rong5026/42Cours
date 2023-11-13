/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:59 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 14:34:27 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name;

    std::cout << "Stack Zombie name: " << std::flush;
    std::cin >> name;
	
	randomChump(name); // 지역변수로 stack에 할당

    std::cout << "Heap Zombie name: " << std::flush;
    std::cin >> name;
	
	Zombie *zombi2 = newZombie(name); // heap에 할당
	zombi2->announce();
	delete zombi2;

	return 0;
}
