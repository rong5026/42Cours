/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:08:25 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 17:11:27 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
    this->brain = new Brain();
    std::cout  << this->type << " has been created." << std::endl;
}

Cat::Cat(const Cat &source) {
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = source;
}

Cat	&Cat::operator=(const Cat& source) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->type = source.type;
        delete this->brain; 
        this->brain = new Brain(*source.brain);
	}
    return (*this);
}

Cat::~Cat(void) {
    delete this->brain;
    std::cout << this->type << " is gone" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meow.." << std::endl;
}

Brain   *Cat::getBrain(void) const {
	return (this->brain);
}