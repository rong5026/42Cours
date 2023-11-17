/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:53:08 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/18 01:24:41 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;

	std::cout << "ScavTrap "  << name << " has been created." << std::endl;
}

ScavTrap::~ScavTrap(void){
   std::cout << "ScavTrap "  << this->name << " is gone" << std::endl;
}

void	ScavTrap::attack(const std::string& target){

	if (this->energy_point == 0 || this->hit_point == 0) {
		std::cout << "ScavTrap No energy or hit_point!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point -= 1;
	}
}

void	ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}