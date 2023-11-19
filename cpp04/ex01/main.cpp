/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:06:31 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 23:50:29 by hong-yeongh      ###   ########.fr       */
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

	return 0;

}