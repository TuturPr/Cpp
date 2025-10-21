/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:11:03 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 02:41:40 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}
AForm* Intern::createForm(const std::string& formType, const std::string& target)
{
	int i = 0;
	
std::string formNames[3] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
};


	while (i < 3 && formType != formNames[i])
		i++;

	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern cannot create form: Unknown form type '" << formType << "'" << std::endl;
			return NULL;
	}
}
