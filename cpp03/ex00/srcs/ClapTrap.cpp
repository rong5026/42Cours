/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:41:53 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/17 20:56:47 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hit_point(10), energy_point(10), attack_damage(0) {
	this->name = name;
    std::cout << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& source) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->name = source.name;
		this->hit_point = source.hit_point;
		this->energy_point = source.energy_point;
		this->attack_damage = source.attack_damage;
	}
    return (*this);

}
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap is gone" << std::endl;
}
