/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:04:34 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 17:35:58 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {

    std::string input;
    Harl	harl;

    while (1)
    {
        std::cout << "input (DEBUG,INFO,WARNING,ERROR) : ";
        std::cin >> input;
        harl.complain(input);
    }

    return (0);
}