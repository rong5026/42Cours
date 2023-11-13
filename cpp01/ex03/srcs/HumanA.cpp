/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:04 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 16:01:22 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void) {
    if (this->weapon.getType() != "") 
	{
        std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
    } 
	else 
	{
        std::cout << this->name << " has no weapons." << std::endl;
    }
}