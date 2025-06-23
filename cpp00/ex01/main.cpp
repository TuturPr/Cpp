/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:18:42 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/16 14:08:16 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook 	phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "End of input detected. Exiting search." << std::endl;
			return (0);
		}
		if (command == "ADD")
			phonebook.init_contact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Exiting the phonebook." << std::endl;
			break;
		}
	}

	return (0);
}
