/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:08:58 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 22:32:17 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	this->type = "WrongAnimal";
    std::cout << this->type << " has been created." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	this->type = type;
    std::cout << this->type << " has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source) {
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = source;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& source) {
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->type = source.type;
	}
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << this->type << " is gone" << std::endl;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal makeSound called!!!" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
    return (this->type);
}