/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:08:21 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 17:11:35 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	this->type = "Animal";
    std::cout << this->type << " has been created." << std::endl;
}

Animal::Animal(std::string type) {
	this->type = type;
    std::cout << this->type << " has been created." << std::endl;
}

Animal::Animal(const Animal &source) {
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = source;
}

Animal	&Animal::operator=(const Animal& source) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->type = source.type;
	}
    return (*this);
}

Animal::~Animal(void) {
    std::cout << "Animal is gone" << std::endl;
}

void Animal::makeSound(void) const {
    std::cout << "Animal makeSound called" << std::endl;
}

std::string	Animal::getType(void) const {
    return (this->type);
}