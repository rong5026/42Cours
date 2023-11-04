/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:23:55 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/04 19:34:07 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

const std::string& Contact::GetFirstName(void) const {
    return this->first_name;
}

const std::string& Contact::GetLastName(void) const {
    return this->last_name;
}

const std::string& Contact::GetNickname(void) const {
    return this->nickname;
}

const std::string& Contact::GetPhoneNumber(void) const {
    return this->phone_number;
}

const std::string& Contact::GetDarkestSecret(void) const {
    return this->darkest_secret;
}

void Contact::SetFirstName(std::string& str) {
    this->first_name = str;
}

void Contact::SetLastName(std::string& str) {
    this->last_name = str;
}

void Contact::SetNickName(std::string& str) {
    this->nickname = str;
}

void Contact::SetPhoneNumber(std::string& str) {
    this->phone_number = str;
}

void Contact::SetDarkestSecret(std::string& str) {
    this->darkest_secret = str;
}
