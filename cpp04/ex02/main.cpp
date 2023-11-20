/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:06:31 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 17:25:10 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	Animal *tmp = new Dog();
	Dog *tmp1 = new Dog();
	Cat *tmp2 = new Cat();
	

	std::cout << "------------------------------" << std::endl;
	for (int i = 0 ; i < 4 ; i++) {
		std::cout << tmp1->getBrain()->getIdeas(i) << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	
	std::cout << tmp->getType() << std::endl;
	std::cout << tmp1->getType() << std::endl;
	std::cout << tmp2->getType() << std::endl;
	std::cout << "------------------------------" << std::endl;

	delete tmp;
	delete tmp1;
	delete tmp2;

	return 0;

}