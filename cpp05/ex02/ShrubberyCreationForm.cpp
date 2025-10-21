/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:43:38 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 01:54:41 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		target = other.target;
		setisSigned(other.getIsSigned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action() const
{
	std::ofstream outfile((target + "_shrubbery").c_str());

	if (!outfile)
		throw ShrubberyCreationForm::FileOpenException();

	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";

	outfile.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "Error: Could not open file.";
}
