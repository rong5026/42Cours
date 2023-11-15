/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:02:07 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/15 23:07:58 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int number;
	static const int fractional_bits = 8;
	
public:
	Fixed(void);
	Fixed(const int int_number);
	Fixed(const float float_number);
	Fixed(const Fixed &source);
	Fixed &operator=(const Fixed &source);
	~Fixed(void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;

}; 
std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif