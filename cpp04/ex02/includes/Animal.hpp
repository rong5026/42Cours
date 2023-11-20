/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:09:28 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 23:20:42 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal(void);
    Animal(std::string type);
    Animal(const Animal &source);
    Animal&	operator=(const Animal &source);
    virtual	~Animal(void);

    virtual void	makeSound(void) const;
	std::string	getType(void) const; 
};

#endif

