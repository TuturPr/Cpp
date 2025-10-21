/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:29:23 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 19:35:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	std::srand(time(0));
	int random = std::rand() % 3;

	switch (random)
	{
		case 0: return new A();
		case 1: return new B();
		case 2:	return new C();
		default: return NULL;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
}

void identify(Base& p) {
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}
}

int main()
{
    Base* base = generate();
    identify(base);
	identify(*base);
    delete base;
    return 0;
}
