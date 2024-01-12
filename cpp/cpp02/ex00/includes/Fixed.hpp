/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:53 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/15 21:59:12 by hong-yeongh      ###   ########.fr       */
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
	Fixed(const Fixed &source);
	Fixed &operator=(const Fixed &source);
	~Fixed(void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
}; 

#endif