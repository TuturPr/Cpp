/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:08:40 by arthur            #+#    #+#             */
/*   Updated: 2025/10/25 15:41:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ctime>

std::vector<int> generateJacobsthalIndices(int n) {
	std::vector<int> indices;

	for (int k = 3;; ++k) {
		int j = int(round((pow(2, k + 1) + pow(-1, k)) / 3));
		if (j > n)
			break;
		indices.push_back(j - 1);
	}

	indices.push_back(0);
	return indices;
}

// ==================== VECTOR ====================

PmergeVector::PmergeVector(char **av) {
	for (int i = 1; av[i]; ++i) {
		std::string token(av[i]);
		std::istringstream ss(token);
		int n;
		char c;
		if (!(ss >> n) || ss.get(c) || n < 0)
			throw std::runtime_error("Error: invalid input");
		if (std::find(container.begin(), container.end(), n) != container.end())
			throw std::runtime_error("Duplicate value detected");
		container.push_back(n);
	}
}


void PmergeVector::sort() {
	start_ = std::clock();
	_sort();
	end_ = std::clock();
}

void PmergeVector::sort_time() {
	std::cout << "Time to process a range of " << container.size()
			  << " elements with std::vector: "
			  << std::fixed << std::setprecision(0)
			  << ((end_ - start_) * 1000000.0 / CLOCKS_PER_SEC)
			  << " us" << std::endl;
}

void PmergeVector::print() {
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}

void PmergeVector::_sort() {
	if (container.size() < 2) return;

	std::vector<std::pair<int,int> > pairs;
	int odd = 0;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i+1])
			pairs.push_back(std::make_pair(container[i], container[i+1]));
		else
			pairs.push_back(std::make_pair(container[i+1], container[i]));
	}
	if (container.size() % 2 == 1)
		odd = container.back();

	std::vector<int> majors;
	for (size_t i = 0; i < pairs.size(); ++i)
		majors.push_back(pairs[i].second);
	std::sort(majors.begin(), majors.end());

	std::vector<int> sorted = majors;
	std::vector<int> minors;
	for (size_t i = 0; i < pairs.size(); ++i)
		minors.push_back(pairs[i].first);

	std::vector<int> order = generateJacobsthalIndices(minors.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		std::vector<int>::iterator it = std::upper_bound(sorted.begin(), sorted.end(), minors[idx]);
		sorted.insert(it, minors[idx]);
	}

	if (odd != 0) {
		std::vector<int>::iterator it = std::upper_bound(sorted.begin(), sorted.end(), odd);
		sorted.insert(it, odd);
	}

	container = sorted;
}

// ==================== DEQUE ====================

PmergeDeque::PmergeDeque(char **av) {
	for (int i = 1; av[i]; ++i) {
		std::string token(av[i]);
		std::istringstream ss(token);
		int n;
		char c;
		if (!(ss >> n) || ss.get(c) || n < 0)
			throw std::runtime_error("Error: invalid input");
		if (std::find(container.begin(), container.end(), n) != container.end())
			throw std::runtime_error("Duplicate value detected");
		container.push_back(n);
	}
}


void PmergeDeque::sort() {
	start_ = std::clock();
	_sort();
	end_ = std::clock();
}

void PmergeDeque::sort_time() {
	std::cout << "Time to process a range of " << container.size()
			  << " elements with std::deque: "
			  << std::fixed << std::setprecision(0)
			  << ((end_ - start_) * 1000000.0 / CLOCKS_PER_SEC)
			  << " us" << std::endl;
}

void PmergeDeque::print() {
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}

void PmergeDeque::_sort() {
	if (container.size() < 2) return;

	std::deque<std::pair<int,int> > pairs;
	int odd = 0;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i+1])
			pairs.push_back(std::make_pair(container[i], container[i+1]));
		else
			pairs.push_back(std::make_pair(container[i+1], container[i]));
	}
	if (container.size() % 2 == 1)
		odd = container.back();

	std::deque<int> majors;
	for (size_t i = 0; i < pairs.size(); ++i)
		majors.push_back(pairs[i].second);
	std::sort(majors.begin(), majors.end());

	std::deque<int> sorted = majors;
	std::deque<int> minors;
	for (size_t i = 0; i < pairs.size(); ++i)
		minors.push_back(pairs[i].first);

	std::vector<int> order = generateJacobsthalIndices(minors.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		std::deque<int>::iterator it = std::upper_bound(sorted.begin(), sorted.end(), minors[idx]);
		sorted.insert(it, minors[idx]);
	}

	if (odd != 0) {
		std::deque<int>::iterator it = std::upper_bound(sorted.begin(), sorted.end(), odd);
		sorted.insert(it, odd);
	}

	container = sorted;
}
