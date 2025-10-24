/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:42:22 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 14:36:24 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	sp.fillRandomNumbers(10000);

	try {
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "small span" << std::endl;
	Span smallSpan = Span(5);
	smallSpan.addNumber(6);
	smallSpan.addNumber(3);
	smallSpan.addNumber(17);
	smallSpan.addNumber(9);
	smallSpan.addNumber(11);

	try {
		std::cout << "Shortest Span: " << smallSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << smallSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
