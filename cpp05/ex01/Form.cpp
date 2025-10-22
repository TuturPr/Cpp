/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:53:46 by ariou             #+#    #+#             */
/*   Updated: 2025/10/22 15:46:13 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("undefined"), is_signed(false), sign_grade(150), exec_grade(150)
{
}

Form::Form(const std::string name, int sign_grade, int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

int Form::getSignGrade() const
{
	return (this->sign_grade);
}

int Form::getExecGrade() const
{
	return (this->exec_grade);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade)
		throw Form::GradeTooLowException();
	if (this->is_signed)
		throw std::runtime_error("Form is already signed");
	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signs " << this->name << "." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form Name: " << form.getName() << std::endl;
	os << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Sign Grade: " << form.getSignGrade() << std::endl;
	os << "Execute Grade: " << form.getExecGrade() << std::endl;
	return (os);
}

