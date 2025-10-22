/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:13:03 by arthur            #+#    #+#             */
/*   Updated: 2025/10/22 17:19:13 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	const char* strArray[] = {"Hello", "World", "from", "iter", "function"};

	std::cout << "Integer Array:" << std::endl;
	iter(intArray, 5, printElement);

	std::cout << "\nString Array:" << std::endl;
	iter(strArray, 5, printElement);

	return 0;
}
