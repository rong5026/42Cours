/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:04:34 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 13:38:10 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    
    Harl	harl;
    std::string input;

    while (1)
    {
        std::cout << "input (DEBUG,INFO,WARNING,ERROR,EXIT) : ";
        std::cin >> input;
        if (input == "EXIT")
            break;
        harl.complain(input);
    }
    return (0);
}