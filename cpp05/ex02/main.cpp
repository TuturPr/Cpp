/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/21 02:09:35 by arthur           ###   ########.fr       */
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

	Bureaucrat high("Fredo", 1);
	Bureaucrat low("Fredouille", 149);
	Bureaucrat mid("Frederiste", 12);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Zaphod");

	std::cout << "\n=== Promotions et rétrogradations ===" << std::endl;
	high.promote();     // devrait afficher une erreur gérée
	low.demote();       // ok
	low.demote();       // devrait afficher une erreur gérée

	std::cout << "\n=== Signatures ===" << std::endl;
	low.signForm(shrub);      // trop bas, affichera message
	high.signForm(shrub);     // succès
	low.signForm(robo);       // trop bas
	high.signForm(robo);      // succès
	high.signForm(pardon);    // succès

	std::cout << "\n=== Exécutions ===" << std::endl;
	low.executeForm(shrub);   // trop bas
	high.executeForm(shrub);  // succès
	high.executeForm(robo);   // succès aléatoire
	high.executeForm(pardon); // succès

	std::cout << "\n=== État final des bureaucrates ===" << std::endl;
	std::cout << high << std::endl;
	std::cout << mid  << std::endl;
	std::cout << low  << std::endl;

	return 0;
}
