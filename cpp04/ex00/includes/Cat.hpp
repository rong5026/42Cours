/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:07:36 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 22:25:19 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	
public:
    Cat(void);
    Cat(const Cat &source);
    Cat&	operator=(const Cat &source);
    ~Cat(void);

    void	makeSound(void) const;
};

#endif
