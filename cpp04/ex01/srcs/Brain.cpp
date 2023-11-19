/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:10:19 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 23:50:36 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	for (int i = 0; i < 100; i++) {
    	this->ideas[i] = 'a' +(i % 26); 
   	}
    std::cout <<  "brain has been created." << std::endl;
}

Brain::Brain(const Brain &source) {
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = source;
}

Brain	&Brain::operator=(const Brain& source) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		for (int i = 0; i < 100; i++ ) {
            this->ideas[i] = source.ideas[i];
        }
	}
    return (*this);
}

Brain::~Brain(void) {
   std::cout << "brain is gone" << std::endl;
}
