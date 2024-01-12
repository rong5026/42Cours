/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:14 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 13:38:16 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
}

HumanB::~HumanB(void)
{
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (this->weapon->getType() != "" && this->weapon != NULL) 
	{
        std::cout << getName() << " attacks with their " << this->weapon->getType() << std::endl;
    } 
	else 
	{
        std::cout << getName() << " has no weapons." << std::endl;
	}
}

const   std::string &HumanB::getName(void) const
{
    return (this->name);
}
