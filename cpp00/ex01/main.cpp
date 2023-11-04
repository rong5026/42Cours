/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:24:06 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/04 19:36:52 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "includes/PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;

void PrintStart(void)
{
    cout << "*-------------------------------------------*\n"
            "|                                           |\n"
            "|          ADD - Add a new contact          |\n"
            "|          SEARCH - Display a contact       |\n"
            "|          EXIT - Exit PhoneBook            |\n"
            "|                                           |\n"
            "*-------------------------------------------*" << endl;
}

bool IsValidInput(const std::string& input) {
	if (input == "ADD" || input == "SEARCH" || input == "EXIT")
		return (true);
	return (false);
}

std::string GetInput(void)
{
    std::string input;

    while (1)
    {
        cout << "input> ";
        getline(cin, input);
        if (cin.eof() == true)
        {
            cin.clear();
            clearerr(stdin);
        }
        if (IsValidInput(input) && !input.empty())
            break;
        cin.clear();
        cout << "Insert a valid input" << endl;
    }
    return input;
}

int main(void)
{
    PhoneBook phoneBook;
    std::string input;

    while (1)
    {
    	PrintStart();
        input = GetInput();
        if (input == "ADD")
            phoneBook.AddContact();
        else if (input == "SEARCH")
            phoneBook.SearchContact();
        else
        {
            cout << "Exit" << endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}
