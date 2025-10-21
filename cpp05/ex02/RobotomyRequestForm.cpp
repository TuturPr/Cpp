/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:55:00 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 01:59:29 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		target = other.target;
		setisSigned(other.getIsSigned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	std::cout << "Bzzzzzz... Drilling " << target << "..." << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		throw RobotomyFailedException();
}

const char *RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
	return "Error: Robotomy failed.";
}
