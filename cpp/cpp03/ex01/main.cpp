/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:48:47 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/18 16:03:38 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap SA("SA"); // HP 100, EG 50, AT 20
	ScavTrap SB("SB"); // HP 100, EG 50, AT 20
	ClapTrap CA("CA"); // HP 10, EG 10, AT 0
	ClapTrap CB("CB"); // HP 10, EG 10, AT 0

	SA.attack("BB");
	SB.takeDamage(3); 

	SA.attack("CC");
	CA.takeDamage(5);

	CA.attack("AA");
	SA.takeDamage(50);
	
	
	SA.showStatus();
	SB.showStatus();
	CA.showStatus();
	CB.showStatus();

	CB.attack("SA");
	SA.takeDamage(49); // 50으로하면 죽으니깐 밑에 guardGate실행 안됨.
	

	SA.showStatus();
	SB.showStatus();
	CA.showStatus();
	CB.showStatus();

	SA.guardGate(); // 체력이 있을때 가능

	SA.beRepaired(20); //energy 포인트가 있을 때 가능
	
	SA.showStatus();
	
	/// CB의 Energy가 없을 때
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);
	CB.beRepaired(1);

	CB.showStatus();

	CB.attack("CB");

	return (0);
}