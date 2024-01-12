/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:57 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 13:38:26 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string name) {
		this->name = name;
	}
    ~Zombie(void);
    void    announce(void);
    const   std::string& getName(void) const;
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif
