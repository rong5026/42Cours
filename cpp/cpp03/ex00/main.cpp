/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:42:24 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/17 21:42:49 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{

	ClapTrap A("A");
	ClapTrap B("B");

	A.attack("B");
	B.takeDamage(1);

	A.attack("B");
	B.takeDamage(8); // A = (10, 8) , B  = (1, 10)

	B.attack("A"); 
	A.takeDamage(10); // A = (0 , 8) , B = (1 ,9)

	B.beRepaired(3); // A = 0 , B = (4, 8)

	A.attack("B"); // 실패

	B.beRepaired(1); // A = 0 , B = (5, 7)
	B.beRepaired(1); // A = 0 , B = (6, 6)
	B.beRepaired(1); // A = 0 , B = (7, 5)
	B.beRepaired(1); // A = 0 , B = (8, 4)
	B.beRepaired(1); // A = 0 , B = (9, 3)
	B.beRepaired(1); // A = 0 , B = (10, 2)
	B.beRepaired(1); // A = 0 , B = (11, 1)
	B.beRepaired(1); // A = 0 , B = (12, 0)

	B.beRepaired(1); // A = 0 , B = (12, 0) energy가 없어서 실패

	return (0);
}