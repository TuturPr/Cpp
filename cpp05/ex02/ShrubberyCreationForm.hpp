/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:43:08 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 01:47:43 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
		void		action() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		class FileOpenException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};
