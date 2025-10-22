/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:08:53 by ariou             #+#    #+#             */
/*   Updated: 2025/10/22 09:55:23 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat testoiuille("Frederic", -8);
	Bureaucrat testitouille("Fredo", 1);
	Bureaucrat testiuille("Fredouille", 149);
	Bureaucrat test("Frederiste", 12);

	testitouille.promote();
	testiuille.demote();
	std::cout << testiuille << std::endl;
	testiuille.demote();
	std::cout << testiuille << std::endl;
	std::cout << testitouille << std::endl;
	std::cout << test << std::endl;
	return(0);
}
