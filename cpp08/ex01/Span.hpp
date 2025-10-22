/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:03:38 by arthur            #+#    #+#             */
/*   Updated: 2025/10/22 21:40:12 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <stdexcept>
#include <numeric>

class Span
{
	Span();
	public:
	    Span(unsigned int n);
	    Span(const Span &other);
	    Span &operator=(const Span &other);
	    ~Span();

	    void addNumber(int number);
	    int shortestSpan() const;
	    int longestSpan() const;
		void fillRandomNumbers(unsigned int n);

	private:
	    std::vector<int> _numbers;
	    unsigned int _maxSize;
};
