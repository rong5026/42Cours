/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:07:42 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 16:50:07 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

private:
    Brain   *brain;
    
public:
	Dog(void);
    Dog(const Dog &source);
    Dog&	operator=(const Dog &source);
    ~Dog(void);

    void	makeSound(void) const;
    Brain   *getBrain(void) const;
};

#endif