/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:17 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/21 16:56:20 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
	std::string str;

	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str <<std::endl;
	std::cout << stringPTR <<std::endl;
	std::cout << &stringREF <<std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR <<std::endl;
	std::cout << stringREF <<std::endl;

	return (0);
}
