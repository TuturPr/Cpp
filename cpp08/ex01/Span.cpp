/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:05:50 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 14:38:10 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span & Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return (*this);

}

int Span::shortestSpan() const
{
	if (!this->_numbers.size())
		throw std::runtime_error("array is empty");
	if (this->_numbers.size() == 1)
		throw std::runtime_error("only one number");

	std::vector<int> tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());

	std::vector<int> difflist(tmp.size());
	std::adjacent_difference(tmp.begin(), tmp.end(), difflist.begin());

	return (*std::min_element(difflist.begin() + 1 , difflist.end()));
}


int Span::longestSpan() const
{
	if (!this->_numbers.size())
		throw std::runtime_error("array is empty");
	if (this->_numbers.size() == 1)
		throw std::runtime_error("only one number");

	int max = *std::max_element(this->_numbers.begin(),this->_numbers.end());
	int min = *std::min_element(this->_numbers.begin(),this->_numbers.end());

	return (max - min);
}

void Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_maxSize)
		throw std::runtime_error("array is full");
	this->_numbers.push_back(number);
}

void Span::fillRandomNumbers(unsigned int n)
{
	std::srand(std::time(0));
	if (n + this->_numbers.size() > this->_maxSize)
		throw std::runtime_error("not enough space to add numbers");
	for (unsigned int i = 0; i < n; i++)
	{
		int number = rand() % 90000000;
		this->_numbers.push_back(number);
	}
}

Span::~Span()
{
}

