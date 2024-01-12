/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:08:39 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 17:21:01 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
    this->brain = new Brain();
    std::cout  << this->type << " has been created." << std::endl;
}

Dog::Dog(const Dog &source) {
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = source;
}

Dog	&Dog::operator=(const Dog& source) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->type = source.type;
        delete this->brain; 
        this->brain = new Brain(*source.brain);
	}
    return (*this);
}

Dog::~Dog(void) {
    delete this->brain;
    std::cout << this->type << " is gone" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Woof-Woof!!!" << std::endl;
}

Brain   *Dog::getBrain(void) const {
	return (this->brain);
}