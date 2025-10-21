/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:53:46 by ariou             #+#    #+#             */
/*   Updated: 2025/10/20 10:57:08 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("undefined"), is_signed(false), sign_grade(150), exec_grade(150)
{
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	try
	{
		if (sign_grade < 1 || exec_grade < 1)
			throw AForm::GradeTooHighException();
		if (sign_grade > 150 || exec_grade > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

int AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int AForm::getExecGrade() const
{
	return (this->exec_grade);
}

void AForm::setisSigned(bool status)
{
	this->is_signed = status;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade)
		throw AForm::GradeTooLowException();
	if (this->is_signed)
		throw std::runtime_error("AForm is already signed");
	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signs " << this->name << "." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm Name: " << AForm.getName() << std::endl;
	os << "Signed: " << (AForm.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Sign Grade: " << AForm.getSignGrade() << std::endl;
	os << "Execute Grade: " << AForm.getExecGrade() << std::endl;
	return (os);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->is_signed)
		throw std::runtime_error("AForm is not signed");
	if (executor.getGrade() > this->exec_grade)
		throw AForm::GradeTooLowException();
	this->action();
}
