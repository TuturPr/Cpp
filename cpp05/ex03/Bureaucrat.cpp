/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:09:18 by ariou             #+#    #+#             */
/*   Updated: 2025/10/22 16:23:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("undefined"), grade(0) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{}

Bureaucrat::~Bureaucrat()
{}

void Bureaucrat::promote()
{

	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::demote()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}


int Bureaucrat::getGrade() const
{
	return(this->grade);
}

const std::string Bureaucrat::getName() const
{
	return(this->name);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &Bureaucrat)
{
	o << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".";
	return o;
}

void Bureaucrat::signForm(AForm &AForm) const
{
	try
	{
		AForm.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << this->name << " couldn't sign AForm " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &AForm) const
{
	try
	{
		AForm.execute(*this);
		std::cout << this->name << " executed " << AForm.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->name << " couldn't execute AForm " << AForm.getName() << " because " << e.what() << std::endl;
	}
}
