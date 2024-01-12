/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:54:39 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/15 21:57:37 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	Fixed a; // eㅣ폴트
	Fixed b( a ); // 복사 생성자
	Fixed c; // 디폴트
	c = b; // 복사 대입 연산자
	
	std::cout << a.getRawBits() << std::endl; 
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0; 
}

