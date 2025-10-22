/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/22 09:52:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	// Création des bureaucrates
	Bureaucrat high("Fredo", 1);
	Bureaucrat mid("Frederiste", 12);
	Bureaucrat low("Fredouille", 149);
	Bureaucrat internB("Intern", 150);

	Intern intern;

	std::cout << "\n=== Intern crée les formulaires ===" << std::endl;
	AForm* shrub = intern.makeForm("ShrubberyCreationForm", "home");
	AForm* robo  = intern.makeForm("RobotomyRequestForm", "Bender");
	AForm* pardon= intern.makeForm("PresidentialPardonForm", "Zaphod");
	AForm* unknown = intern.makeForm("UnknownForm", "Nobody"); // non existant

	std::cout << "\n=== Signatures ===" << std::endl;
	internB.signForm(*shrub);  // bad
	low.signForm(*shrub);      // bad
	high.signForm(*shrub);     // good
	high.signForm(*robo);      // good
	high.signForm(*pardon);    // good

	std::cout << "\n=== Exécutions ===" << std::endl;
	internB.executeForm(*shrub); // bad
	low.executeForm(*shrub);     // bad
	high.executeForm(*shrub);    // good
	high.executeForm(*robo);     // good
	high.executeForm(*pardon);   // good

	std::cout << "\n=== État final des bureaucrates ===" << std::endl;
	std::cout << high << std::endl;
	std::cout << mid  << std::endl;
	std::cout << low  << std::endl;
	std::cout << internB << std::endl;

	delete shrub;
	delete robo;
	delete pardon;
	delete unknown;

	return 0;
}

