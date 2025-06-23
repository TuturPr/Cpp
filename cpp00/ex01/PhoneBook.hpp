/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:16:53 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/16 14:11:04 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Contact.hpp"


class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook();
		void init_contact(void);
		void searchContact(void) const;
		void print_contacts_list() const;
	private:
		Contact _contacts[8];

		int _currentIndex;
		int _totalContacts;
		enum contactFields
		{
			FIRST_NAME = 0,
			LAST_NAME,
			NICKNAME,
			PHONE_NUMBER,
			DARKEST_SECRET,
		};
};

