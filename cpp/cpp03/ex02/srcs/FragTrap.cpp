/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:11:40 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/18 16:24:18 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->name = "FragTrap";
	this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap " << this->name << " has been created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;

	std::cout << "FragTrap "  << name << " has been created." << std::endl;
}

FragTrap::~FragTrap(void) {
   std::cout << "FragTrap "  << this->name << " is gone" << std::endl;
}

void	FragTrap::attack(const std::string& target) {

	if (this->energy_point == 0 || this->hit_point == 0) {
		std::cout << "FragTrap No energy or hit_point!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point -= 1;
	}
}

void	FragTrap::highFivesGuys(void) {
   	if (this->energy_point == 0 || this->hit_point == 0) {
		std::cout << "FragTrap No energy or hit_point!" << std::endl;
	}
	else {
		std::cout << "FragTrap Hey! Give me some high fives!" << std::endl;
	}
}