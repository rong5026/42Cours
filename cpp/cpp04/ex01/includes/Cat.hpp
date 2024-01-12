/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:09:25 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/20 16:47:41 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain   *brain;
	
public:
    Cat(void);
    Cat(const Cat &source);
    Cat&    operator=(const Cat &source);
    ~Cat(void);

    void	makeSound(void) const;
    Brain   *getBrain(void) const;
};

#endif
