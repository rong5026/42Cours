/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:49:10 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/18 16:10:53 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hit_point(10), energy_point(10), attack_damage(0) {
	this->name = "ClapTrap";
    std::cout << "ClapTrap " << this->name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hit_point(10), energy_point(10), attack_damage(0) {
	this->name = name;
    std::cout << "ClapTrap " << this->name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = source;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& source) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &source) { // 자기 자신에 대한 할당을 확인
		this->name = source.name;
		this->hit_point = source.hit_point;
		this->energy_point = source.energy_point;
		this->attack_damage = source.attack_damage;
	}
    return (*this);

}
ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap "  << this->name << " is gone" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_point == 0 || this->hit_point == 0) {
		std::cout << "ClapTrap No energy or hit_point!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_point == 0 || this->hit_point <= amount)
    {
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		this->hit_point = 0;
    }
	else {
    	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;
		this->hit_point -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point == 0 || this->hit_point == 0) {
		std::cout << "ClapTrap No energy or hit_point!" << std::endl;
	}
	else {
		this->energy_point -= 1;
		this->hit_point += amount;
		std::cout << "ClapTrap " << this->name << " has been repaired and gained " << amount << " hit points" << std::endl;
	}
}

void	ClapTrap::showStatus(void) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << this->name << " - Hit point : " << this->hit_point << ", Energy points : " << this->energy_point << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

