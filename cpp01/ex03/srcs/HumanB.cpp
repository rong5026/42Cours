/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:14 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 16:03:47 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name) {
    this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon( Weapon& weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack(void) {
    if (this->weapon->getType() != "" && this->weapon != NULL) 
	{
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } 
	else 
	{
        std::cout << this->name << " has no weapons." << std::endl;
	}
}
