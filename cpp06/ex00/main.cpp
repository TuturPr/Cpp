/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:24:42 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 18:38:23 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
