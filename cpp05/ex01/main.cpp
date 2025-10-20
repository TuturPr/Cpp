/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/20 11:09:09 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat testoiuille("Frederic", -8);
	Bureaucrat testitouille("Fredo", 1);
	Bureaucrat testiuille("Fredouille", 149);
	Bureaucrat test("Frederiste", 12);
	Form formA("FormA", 2, 10);
	Form formB("FormB", 150, 150);

	//Bureaucrat E;

	testitouille.promote();
	testiuille.demote();
	testiuille.signForm(formA);
	testitouille.signForm(formA);
	testiuille.signForm(formB);
	std::cout << testiuille << std::endl;
	testiuille.demote();
	std::cout << testiuille << std::endl;
	std::cout << testitouille << std::endl;
	std::cout << test << std::endl;
	return(0);
}
