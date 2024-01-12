/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:04 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 13:38:17 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
    if (this->weapon.getType() != "") 
	{
        std::cout << getName() << " attacks with their " << this->weapon.getType() << std::endl;
    } 
	else 
	{
        std::cout <<getName() << " has no weapons." << std::endl;
    }
}

const   std::string &HumanA::getName(void) const
{
    return (this->name);
}
