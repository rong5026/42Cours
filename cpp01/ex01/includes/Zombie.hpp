/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:49:23 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 11:32:32 by hong-yeongh      ###   ########.fr       */
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
    Zombie(void);
    ~Zombie(void);
    void    announce(void);
    void    setName(std::string name);
    const   std::string& getName(void) const;
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
