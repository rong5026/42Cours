/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:28:51 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 13:38:18 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon	&weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    void    attack(void);
    const   std::string& getName(void) const;
};

#endif