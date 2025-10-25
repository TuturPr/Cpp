/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:08:37 by arthur            #+#    #+#             */
/*   Updated: 2025/10/25 14:14:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <numbers...>\n";
		return 1;
	}

	try {
		std::cout << "=== Using std::vector ===" << std::endl;
		PmergeVector vecSorter(argv);
		std::cout << "Before sorting: ";
		vecSorter.print();
		vecSorter.sort();
		std::cout << "After sorting:  ";
		vecSorter.print();
		vecSorter.sort_time();

		std::cout << "\n=== Using std::deque ===" << std::endl;
		PmergeDeque deqSorter(argv);
		std::cout << "Before sorting: ";
		deqSorter.print();
		deqSorter.sort();
		std::cout << "After sorting:  ";
		deqSorter.print();
		deqSorter.sort_time();
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
