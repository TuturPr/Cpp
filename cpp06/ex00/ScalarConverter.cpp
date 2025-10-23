/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:25:11 by arthur            #+#    #+#             */
/*   Updated: 2025/10/23 15:27:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cfloat>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void convertChar(const std::string& literal)
{
	std::cout << "char: '" << literal[0] << "'" << '\n';
	std::cout << "int: " << static_cast<int>(literal[0]) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << '\n';
}

static void convertInt(const std::string& literal)
{

	long getter = atol(literal.c_str());
	if (getter > INT_MAX || getter < INT_MIN)
	{
		std::cout << "Error: Integer overflow" << '\n';
		return ;
	}
	int number = static_cast<int>(getter);
	std::cout << number << '\n';
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
	float number = strtof(literal.c_str(), NULL);

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
	double number = strtod(literal.c_str(), NULL);

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
	std::cout << "Error: Invalid literal" << '\n';
}

void ScalarConverter::convert(const std::string& literal)
{
	try
	{
		if (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff")
		{
			convertSpecial(literal);
		}
		else if (literal.length() == 1 && std::isprint(literal[0]) && !isdigit(literal[0]))
		{
			convertChar(literal);
		}
		else if (literal[literal.length() - 1] == 'f')
		{
			size_t i = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
			while (i < literal.length() - 1 && (isdigit(literal[i]) || literal[i] == '.'))
				i++;
			if (i == literal.length() - 1)
				convertFloat(literal);
			else
				convertError();
		}
		else if (literal.find('.') != std::string::npos)
		{
			size_t i = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
			while (i < literal.length() && (isdigit(literal[i]) || literal[i] == '.'))
				i++;
			if (i == literal.length())
				convertDouble(literal);
			else
				convertError();
		}
		else if (isdigit(literal[0]) || ((literal[0] == '+' || literal[0] == '-') && isdigit(literal[1])))
		{
			size_t i = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
			while (i < literal.length() && isdigit(literal[i]))
				i++;
			if (i == literal.length())
				convertInt(literal);
			else
				convertError();
		}
		else
		{
			convertError();
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
