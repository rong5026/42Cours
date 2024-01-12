/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:44:00 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/04 19:45:01 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_CONTACT_INDEX 7

class PhoneBook {
	
	private:
		size_t count;
		Contact contacts[MAX_CONTACTS];

	public:
		PhoneBook();
    	~PhoneBook();
		void AddContact(void);
		void SearchContact(void);
};

#endif