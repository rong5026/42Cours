/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:06:31 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 22:45:53 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	j->makeSound(); //will output the cat sound! 
	i->makeSound();
    meta->makeSound();

	
	const WrongAnimal* tmp = new WrongAnimal();
	const WrongAnimal* tmp2 = new WrongCat();

	std::cout << tmp->getType() << " " << std::endl; 
	std::cout << tmp2->getType() << " " << std::endl; 

	tmp->makeSound();
	tmp2->makeSound();

	delete meta;
	delete i;
	delete j;
	delete tmp;
	delete tmp2;


	
	return 0; 
}