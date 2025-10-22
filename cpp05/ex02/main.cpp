/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/22 16:22:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrubForm("Home");
		RobotomyRequestForm roboForm("Marvin");
		PresidentialPardonForm presForm("Arthur");

		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);

		bob.signForm(roboForm);
		bob.executeForm(roboForm);

		bob.signForm(presForm);
		bob.executeForm(presForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat tooLowBob("Bob2", 150);
		ShrubberyCreationForm shrubForm("Home");
		RobotomyRequestForm roboForm("Marvin");
		PresidentialPardonForm presForm("Arthur");
		tooLowBob.signForm(shrubForm);
		tooLowBob.executeForm(shrubForm);
		tooLowBob.signForm(roboForm);
		tooLowBob.executeForm(roboForm);
		tooLowBob.signForm(presForm);
		tooLowBob.executeForm(presForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat outofrangeBob("Bob3", 200);
		ShrubberyCreationForm shrubForm("Home");
		RobotomyRequestForm roboForm("Marvin");
		PresidentialPardonForm presForm("Arthur");
		outofrangeBob.signForm(shrubForm);
		outofrangeBob.executeForm(shrubForm);
		outofrangeBob.signForm(roboForm);
		outofrangeBob.executeForm(roboForm);
		outofrangeBob.signForm(presForm);
		outofrangeBob.executeForm(presForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
