/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:49:23 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 14:55:56 by hong-yeongh      ###   ########.fr       */
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
    ~Zombie(void);
    void    announce(void);
    void    setName(std::string name);

};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );
Zombie*    zombieHorde(int N, std::string name );

#endif
