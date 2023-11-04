/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:59:56 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/04 17:09:17 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

std::string set_upper(std::string arg)
{
    for (size_t i = 0; i < arg.length(); i += 1)
        arg[i] = toupper(arg[i]);
    return arg;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else
	{
		for (int i = 1; i < argc; i += 1)
        	cout << set_upper(argv[i]);
    	cout << endl;
	}
    return (EXIT_SUCCESS);
}