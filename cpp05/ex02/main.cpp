/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/22 09:54:53 by arthur           ###   ########.fr       */
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
	high.promote();     // bad
	low.demote();       // good
	low.demote();       // bad

	std::cout << "\n=== Signatures ===" << std::endl;
	low.signForm(shrub);      // bad
	high.signForm(shrub);     // good
	low.signForm(robo);       // bad
	high.signForm(robo);      // good
	high.signForm(pardon);    // good

	std::cout << "\n=== Exécutions ===" << std::endl;
	low.executeForm(shrub);   // bad
	high.executeForm(shrub);  // good
	high.executeForm(robo);   // good
	high.executeForm(pardon); // good

	std::cout << "\n=== État final des bureaucrates ===" << std::endl;
	std::cout << high << std::endl;
	std::cout << mid  << std::endl;
	std::cout << low  << std::endl;

	return 0;
}
