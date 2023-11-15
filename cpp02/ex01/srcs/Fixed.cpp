/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:02:14 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/15 23:29:48 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

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
    return (this->number);
}

void	Fixed::setRawBits(int const raw) {
    this->number = raw;
}

Fixed::Fixed(const int int_number) : number(int_number << fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_number) : number(std::roundf(float_number * (1 << fractional_bits))) {
    std::cout << "Float constructor called" << std::endl;
}


float	Fixed::toFloat(void) const { // 고정을 부동
	return ((float)this->number / (float)(1 << Fixed::fractional_bits));
}

int	Fixed::toInt(void) const {
	return (this->number >> Fixed::fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed)
{
	out << Fixed.toFloat();
	return (out);
}


