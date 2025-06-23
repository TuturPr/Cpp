/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:07:32 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/16 14:13:09 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
}

Contact::~Contact( void )
{
}

void Contact::addContact(void)
{
	static const std::string fieldNames[5] = {
		"First Name",
		"Last Name",
		"Nickname",
		"Phone Number",
		"Darkest Secret"
	};

	std::cout << "Adding a new contact..." << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Enter " << fieldNames[i] << ": ";
		std::getline(std::cin, _fields[i]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "End of input detected. Exiting search." << std::endl;
			break ;
		}
		if (_fields[i].empty() || _fields[i].find_first_not_of(' ') == std::string::npos)
		{
			std::cout << "Field cannot be empty. Please try again." << std::endl;
			--i;
			continue;
		}
	}
	std::cout << "Contact added successfully!" << std::endl;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 10 - 1) + '.';
	return (str);
}

void Contact::print_column(int fieldIndex) const
{
	std::string str = _fields[fieldIndex];
	std::cout << std::setw(10) << truncate(str) << "|";
}

void Contact::displayContact(void) const
{
	std::cout << "First Name: " << _fields[FIRST_NAME] << std::endl;
	std::cout << "Last Name: " << _fields[LAST_NAME] << std::endl;
	std::cout << "Nickname: " << _fields[NICKNAME] << std::endl;
	std::cout << "Phone Number: " << _fields[PHONE_NUMBER] << std::endl;
	std::cout << "Darkest Secret: " << _fields[DARKEST_SECRET] << std::endl;
}
