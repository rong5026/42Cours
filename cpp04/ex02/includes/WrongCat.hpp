/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:07:53 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 22:34:52 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{

public:
	WrongCat(void);
	WrongCat(const WrongCat &source);
	WrongCat&	operator=(const WrongCat &source);
	~WrongCat(void);

	void	makeSound(void) const;
};

#endif