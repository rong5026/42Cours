/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:11:21 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/18 16:33:57 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap SA("SA"); // HP 100, EG 50, AT 20
	FragTrap FA("FA"); // HP 100, EG 100, AT 30
	ClapTrap CA("CA"); // HP 10, EG 10, AT 0
	

	SA.attack("FA");
	FA.takeDamage(20);

	SA.showStatus();
	FA.showStatus();

	FA.attack("CA");
	CA.takeDamage(30);

	FA.showStatus();
	CA.showStatus();

	SA.guardGate();
	FA.highFivesGuys();
	FA.beRepaired(11);

	SA.showStatus();
	FA.showStatus();


	return (0);
}