/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:53:39 by ariou             #+#    #+#             */
/*   Updated: 2025/10/20 11:00:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"


class Bureaucrat;
class AForm
{
	private:
		AForm();
		const std::string	name;
		bool 				is_signed;
		const int			sign_grade;
		const int			exec_grade;
		virtual void		action() const = 0;
	public:
		AForm(const std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();
		const std::string getName() const;
		bool getIsSigned() const;
		void setisSigned(bool status);
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

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

std::ostream &operator<<(std::ostream &os, const AForm &AForm);
