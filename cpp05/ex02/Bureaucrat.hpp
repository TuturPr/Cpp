/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:09:10 by ariou             #+#    #+#             */
/*   Updated: 2025/10/21 02:02:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		Bureaucrat();
		const std::string name;
		int grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void promote();
		void demote();
		void signForm(AForm &AForm) const;
		void executeForm(const AForm &AForm) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &Bureaucrat);

