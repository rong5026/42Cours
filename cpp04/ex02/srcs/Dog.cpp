/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:08:39 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 23:50:04 by hong-yeongh      ###   ########.fr       */
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
        this->brain = new Brain(*source.brain);
	}
    return (*this);
}

Dog::~Dog(void) {
    std::cout << this->type << " is gone" << std::endl;
    delete this->brain;
}

void Dog::makeSound(void) const {
    std::cout << "Woof-Woof!!!" << std::endl;
}
