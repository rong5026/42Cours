/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:06:31 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 17:11:44 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	// const Animal* j = new Dog(); 
	// const Animal* i = new Cat();
	
	// delete j;//should not create a leak 
	// delete i;
	
	// return 0; 

	Animal* animal[4];

	animal[0] = new Dog();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Cat();

	for (int i = 0; i < 4; i++) {
		delete animal[i];
	}

	Dog *tmp = new Dog();

	std::cout << "------------------------------" << std::endl;
	for (int i = 0 ; i < 4 ; i++) {
		std::cout << tmp->getBrain()->getIdeas(i) << std::endl;
	}
	std::cout << "------------------------------" << std::endl;

	delete tmp;

	return 0;

}