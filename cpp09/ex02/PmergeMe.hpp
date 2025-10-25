/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:08:43 by arthur            #+#    #+#             */
/*   Updated: 2025/10/25 18:29:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeVector {
public:
	PmergeVector(char **av);
	void sort();
	void sort_time();
	void print();

private:
	std::vector<int> container;
	std::clock_t start_, end_;
	void _sort();
};

class PmergeDeque {
public:
	PmergeDeque(char **av);
	void sort();
	void sort_time();
	void print();

private:
	std::deque<int> container;
	std::clock_t start_, end_;
	void _sort();
};

