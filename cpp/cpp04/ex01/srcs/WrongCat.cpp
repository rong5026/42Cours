/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:08:54 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 16:42:23 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
    std::cout  << this->type << " has been created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) {
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = source;
}

WrongCat	&WrongCat::operator=(const WrongCat& source) {
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->type = source.type;
	}
    return (*this);
}

WrongCat::~WrongCat(void) {
    std::cout << this->type << " is gone" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "MMMMMMMMMeHHHHHHHow.." << std::endl;
}