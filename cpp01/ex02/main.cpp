/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:06 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 15:15:58 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << &str << "| value : " << str << std::endl;
    std::cout << stringPTR << "| value : " << *stringPTR << std::endl;
    std::cout << &stringREF << "| value : " << stringREF << std::endl;

    return 0;
}