/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:28:49 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 15:49:23 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon	*weapon;

public:
    HumanB(std::string name);
    ~HumanB();
    void    attack(void);
    void    setWeapon(Weapon &weapon);
};

#endif
