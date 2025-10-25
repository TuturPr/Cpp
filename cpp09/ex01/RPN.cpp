/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:02:47 by arthur            #+#    #+#             */
/*   Updated: 2025/10/25 14:35:49 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>



RPN::RPN() : _stack()
{
}

RPN::RPN(std::stack<double> stack) : _stack(stack)
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculate(const std::string &input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (isdigit(token[0]) && token.size() == 1)
			_stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: Not enough operands for operation '" << token << "'" << std::endl;
				return;
			}
			double b = _stack.top(); _stack.pop();
			double a = _stack.top(); _stack.pop();
			double result;

			if (token == "+") result = a + b;
			else if (token == "-") result = a - b;
			else if (token == "*") result = a * b;
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return;
				}
				result = a / b;
			}
			_stack.push(result);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}

	std::cout << _stack.top() << std::endl;
	_stack.pop();
}
