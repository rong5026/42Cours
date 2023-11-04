/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:23:52 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/04 19:37:21 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip>
#include <iostream>

class Contact 
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
 	Contact();
    ~Contact();
	void SetFirstName(std::string& str);
	void SetLastName(std::string& str);
	void SetNickName(std::string& str);
	void SetPhoneNumber(std::string& str);
	void SetDarkestSecret(std::string& str);

	const std::string&	GetFirstName(void) const;
	const std::string&	GetLastName(void) const;
	const std::string&	GetNickname(void) const;
	const std::string&	GetPhoneNumber(void) const;
	const std::string&	GetDarkestSecret(void) const;
};

#endif
