/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:02:14 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/16 14:57:01 by hong-yeongh      ###   ########.fr       */
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

// 6개 비교 오퍼레이터

bool	Fixed::operator>(const Fixed &other) const {
    return (this->getRawBits() > other.getRawBits());
}

bool    Fixed::operator<(const Fixed &other) const {
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator>=(const Fixed &other) const {
    return (this->getRawBits() >= other.getRawBits());
}

bool    Fixed::operator<=(const Fixed &other) const {
    return (this->getRawBits() <= other.getRawBits());
}

bool    Fixed::operator==(const Fixed &other) const {
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed &other) const {
    return (this->getRawBits() != other.getRawBits());
}

// 4개 연산자

Fixed   Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// 후위, 전위 연산자
// 전위 증가
Fixed   &Fixed::operator++(void) {
    this->number += 1;
    return (*this);
}
// 후위 증가
Fixed   Fixed::operator++(int) {
    Fixed tmp(*this);
    this->number += 1;
    return (tmp);
}

Fixed& Fixed::operator--(void) {
    this->number -= 1;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->number -= 1;
    return (tmp);
}

// 최대 최소

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const   Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const   Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}