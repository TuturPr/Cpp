/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/21 13:20:11 by arthur           ###   ########.fr       */
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
	std::srand(std::time(0)); // Initialisation du hasard pour Robotomy

	// Création des bureaucrates
	Bureaucrat high("Fredo", 1);
	Bureaucrat mid("Frederiste", 12);
	Bureaucrat low("Fredouille", 149);
	Bureaucrat internB("Intern", 150); // grade minimal

	// Création de l'intern
	Intern intern;

	std::cout << "\n=== Intern crée les formulaires ===" << std::endl;
	AForm* shrub = intern.createForm("ShrubberyCreationForm", "home");
	AForm* robo  = intern.createForm("RobotomyRequestForm", "Bender");
	AForm* pardon= intern.createForm("PresidentialPardonForm", "Zaphod");
	AForm* unknown = intern.createForm("UnknownForm", "Nobody"); // test form inexistant

	std::cout << "\n=== Signatures ===" << std::endl;
	internB.signForm(*shrub);  // trop bas, refus
	low.signForm(*shrub);      // trop bas
	high.signForm(*shrub);     // succès
	high.signForm(*robo);      // succès
	high.signForm(*pardon);    // succès

	std::cout << "\n=== Exécutions ===" << std::endl;
	internB.executeForm(*shrub); // refus
	low.executeForm(*shrub);     // refus
	high.executeForm(*shrub);    // succès
	high.executeForm(*robo);     // succès aléatoire
	high.executeForm(*pardon);   // succès

	std::cout << "\n=== État final des bureaucrates ===" << std::endl;
	std::cout << high << std::endl;
	std::cout << mid  << std::endl;
	std::cout << low  << std::endl;
	std::cout << internB << std::endl;

	// Clean up (libération mémoire)
	delete shrub;
	delete robo;
	delete pardon;
	delete unknown;

	return 0;
}

