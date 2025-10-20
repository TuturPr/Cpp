/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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
class Form
{
	private:
		Form();
		const std::string	name;
		bool 				is_signed;
		const int			sign_grade;
		const int			exec_grade;
	public:
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &os, const Form &form);
