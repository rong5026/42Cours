/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:55:24 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/15 21:59:13 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout <<"Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const Fixed &source) {
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source) // 자기 자신에 대한 할당을 확인
		this->setRawBits(source.getRawBits());
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number);
}

void	Fixed::setRawBits(int const raw) {
    this->number = raw;
}