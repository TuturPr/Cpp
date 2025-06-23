/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:16:55 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/16 14:08:41 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _currentIndex(0), _totalContacts(0)
{
}

PhoneBook::~PhoneBook( void )
{
}

void PhoneBook::init_contact(void)
{
	_contacts[_currentIndex].addContact();

	_currentIndex = (_currentIndex + 1) % 8;
	if (_totalContacts < 8)
		_totalContacts++;
}

void PhoneBook::print_contacts_list() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "\n";

	for (int i = 0; i < 8; ++i) {
		std::cout << std::setw(10) << i << "|";
		_contacts[i].print_column(FIRST_NAME);
		std::cout << "|";
		_contacts[i].print_column(LAST_NAME);
		std::cout << "|";
		_contacts[i].print_column(NICKNAME);
		std::cout << "\n";
	}
}

void PhoneBook::searchContact(void) const
{
	std::cout << "Contacts in phonebook:" << std::endl;
	print_contacts_list();

	if (_totalContacts == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::string input;
	int index;
	std::cout << "Enter index of contact to display (0-7): ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::cout << "End of input detected. Exiting search." << std::endl;
		exit(0);
	}
	std::istringstream iss(input);
	if (!(iss >> index) || index < 0 || index >= _totalContacts)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}
	std::cout << "Displaying contact at index " << index << ":" << std::endl;
	_contacts[index].displayContact();
}

