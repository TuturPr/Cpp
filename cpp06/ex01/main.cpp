/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:17:40 by arthur            #+#    #+#             */
/*   Updated: 2025/10/21 19:19:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data		data;
	Data*		dataPtr;
	uintptr_t	raw;

	data.n = 42;
	std::cout << "Original data address: " << &data << ", n = " << data.n << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << "Serialized data (uintptr_t): " << raw << std::endl;

	dataPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized data address: " << dataPtr << ", n = " << dataPtr->n << std::endl;

	return 0;
}
