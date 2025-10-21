/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:10:59 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 02:12:29 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	AForm* createForm(const std::string& formType, const std::string& target);

};
