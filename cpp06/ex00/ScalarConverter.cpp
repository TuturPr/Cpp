/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:25:11 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 18:52:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cfloat>

static void convertChar(const std::string& literal)
{
	std::cout << "char: '" << literal[0] << "'" << '\n';
	std::cout << "int: " << static_cast<int>(literal[0]) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << '\n';
}

static void convertInt(const std::string& literal)
{
	int number = atoi(literal.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: Impossible" << '\n';
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(number) << '\n';
	std::cout << "int: " << number << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << '\n';
}

static void convertFloat(const std::string& literal)
{
	float number = atof(literal.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: Impossible" << '\n';
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(number) << '\n';
	std::cout << "int: " << static_cast<int>(number) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(2) << number << 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(number) << '\n';
}

static void convertDouble(const std::string& literal)
{
	double number = atof(literal.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: Impossible" << '\n';
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(number) << '\n';
	std::cout << "int: " << static_cast<int>(number) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(number) << 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(2) << number << '\n';
}

static void convertSpecial(const std::string& literal)
{
	std::cout << "char: Impossible" << '\n';
	std::cout << "int: Impossible" << '\n';
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << '\n';
		std::cout << "double: nan" << '\n';
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << '\n';
		std::cout << "double: +inf" << '\n';
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << '\n';
	std::cout << "double: -inf" << '\n';
	}
}

static void convertError()
{
	std::cout << "char : Impossible" << '\n';
	std::cout << "int : Impossible" << '\n';
	std::cout << "float : Impossible" << '\n';
	std::cout << "double : Impossible" << '\n';
}

void ScalarConverter::convert(const std::string& literal)
{
	if (std::isprint(literal[0]) && !isdigit(literal[0]))
		if (literal.length() == 1)
			convertChar(literal);
		else if (literal == "nan" || literal == "nanf" ||
				 literal == "+inf" || literal == "+inff" ||
				 literal == "-inf" || literal == "-inff")
			convertSpecial(literal);
		else
			convertError();
	else if (literal.length() - 1 == 'f')
	{
		size_t i = 0;
		while (i < literal.length() - 1 && (isdigit(literal[i]) || literal[i] == '.'))
			i++;
		if (i == literal.length() - 1)
			convertFloat(literal);
		else
			convertError();
	}
	else if (literal.find('.') != std::string::npos)
	{
		size_t i = 0;
		while (isdigit(literal[i]) || literal[i] == '.')
			i++;
		if (i == literal.length() - 1)
			convertDouble(literal);
		else
			convertError();
	}
	else if (isdigit(literal[0]) || ((literal[0] == '+' || literal[0] == '-') && isdigit(literal[1])))
	{
		size_t i = 0;
		if (literal[0] == '+' || literal[0] == '-')
			i++;
		while (i < literal.length() && isdigit(literal[i]))
			i++;
		if (i == literal.length())
			convertInt(literal);
		else
			convertError();
	}
	else
		convertError();
}
