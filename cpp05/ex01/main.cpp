/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/09/26 17:53:20 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat testoiuille("Frederic", -8);
	Bureaucrat testitouille("Fredo", 1);
	Bureaucrat testiuille("Fredouille", 149);
	Bureaucrat test("Frederiste", 12);
	//Bureaucrat E;

	testitouille.promote();
	testiuille.demote();
	std::cout << testiuille << std::endl;
	testiuille.demote();
	std::cout << testiuille << std::endl;
	std::cout << testitouille << std::endl;
	std::cout << test << std::endl;
	return(0);
}
