/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:53:39 by ariou             #+#    #+#             */
/*   Updated: 2025/09/26 18:20:29 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool 				is_signed;
		const int			sign_grade;
		const int			exec_grade;
	public:
		Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		void beSigned(Bureaucrat &bureaucrat);

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


