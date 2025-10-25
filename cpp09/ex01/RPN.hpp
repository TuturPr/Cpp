/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:02:49 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 22:20:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(std::stack<double> stack);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void calculate(const std::string &input);
	private:
		std::stack<double> _stack;

};
