/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:53:46 by ariou             #+#    #+#             */
/*   Updated: 2025/09/26 18:18:19 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{}

Form::~Form()
{
}


const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
