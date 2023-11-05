/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:52 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/04 19:44:56 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

using std::cout;
using std::cin;
using std::endl;

PhoneBook::PhoneBook() : count(0) {
}

PhoneBook::~PhoneBook()
{
}

std::string GetFormattedField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	return field;
}

void DisplayResult(Contact contact)
{
	cout << endl;
	cout << "First name: " << contact.GetFirstName() << endl;
	cout << "Last name: " << contact.GetLastName() << endl;
	cout << "Nickname: " << contact.GetNickname() << endl;
	cout << "Phone number: " << contact.GetPhoneNumber() << endl;
	cout << "Darkest secret: " << contact.GetDarkestSecret() << endl;
	cout << endl;
}

void inputPhoneElem(Contact& new_contact, std::string type, std::string message)
{
	std::string	input;

	while (1)
	{
		cout <<  message;
		getline(cin, input);
		if (input.empty()) 
		{
			cin.clear();
			cout << "Insert a valid input" << endl;
			continue;
		}
		if (type == "First")
			new_contact.SetFirstName(input);
		else if (type == "Last")
			new_contact.SetLastName(input);
		else if (type == "Nick")
			new_contact.SetNickName(input);
		else if (type == "Phone")
			new_contact.SetPhoneNumber(input);
		else if (type == "Darkest")
			new_contact.SetDarkestSecret(input);
		break;
	}
}
void PhoneBook::AddContact(void)
{
	Contact	new_contact;
	std::string	input;

	inputPhoneElem(new_contact, "First", "First Name: ");
	inputPhoneElem(new_contact, "Last", "Last Name: ");
	inputPhoneElem(new_contact, "Nick", "Nick Name: ");
	inputPhoneElem(new_contact, "Phone", "Phone Number: ");
	inputPhoneElem(new_contact, "Darkest", "Darkest secret (Yes or No) : ");

	if (count > MAX_CONTACT_INDEX)
		this->contacts[count - 1] = new_contact;
	else
	{
		this->count += 1;
		this->contacts[count - 1] = new_contact;
	}
	cout << "Contact was added" << endl;
}

void PhoneBook::SearchContact(void)
{
	if (count == 0)
	{
		cout << "Empty Contact" << endl;
		return ;
	}
	cout << "\n|     Index|First Name| Last Name|  Nickname|" << endl;
	for (size_t i = 0; i < this->count; i += 1)
	{
		cout << "|" << std::right << std::setw(10) << i << "|";
		cout << std::right << std::setw(10) << GetFormattedField(contacts[i].GetFirstName()) << "|" ;
		cout << std::right << std::setw(10) << GetFormattedField(contacts[i].GetLastName()) << "|";
		cout << std::right << std::setw(10) << GetFormattedField(contacts[i].GetNickname()) << "|";
		cout << endl;
	}

	std::string index;
	int contact_idx;

	while (1)
	{
		cout << "Index Number : ";
		getline(cin, index);
		if (!index.empty() && index.find_first_not_of("0123456789") == std::string::npos)
		{
			contact_idx = atoi(index.c_str());
			if (contact_idx <= MAX_CONTACT_INDEX)
				break;
		}
		cin.clear();
		cout << "Invalid input" << endl;
	}
	if ((size_t)contact_idx > (count - 1))
		cout << "Insert a valid Index Number" << endl;
	else
		DisplayResult(this->contacts[contact_idx]);
}
