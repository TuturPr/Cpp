/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:52:55 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 14:40:53 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	std::cout << "=== Tests basiques ===" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\n=== Parcours avec iterateurs ===" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\n=== Copie dans std::stack ===" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Top de la copie: " << s.top() << std::endl;

	std::cout << "\n=== Tests sur une MutantStack<string> ===" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");
	for (MutantStack<std::string>::iterator sit = strStack.begin(); sit != strStack.end(); ++sit)
		std::cout << *sit << " ";
	std::cout << std::endl;

	std::cout << "\n=== Tests sur une pile vide ===" << std::endl;
	MutantStack<int> empty;
	std::cout << "Empty? " << (empty.empty() ? "yes" : "no") << std::endl;
	empty.push(42);
	std::cout << "After push, empty? " << (empty.empty() ? "yes" : "no") << std::endl;
	std::cout << "Top: " << empty.top() << std::endl;

	return 0;
}
