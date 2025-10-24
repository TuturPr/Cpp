/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:40:53 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 10:16:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {

	try {
		std::cout << "\nTest du constructeur par défaut :" << std::endl;
		Array<int> a;
		std::cout << "Taille de a : " << a.size() << std::endl;

		std::cout << "\nTest du constructeur avec taille :" << std::endl;
		Array<int> b(5);
		std::cout << "Taille de b : " << b.size() << std::endl;
		for (unsigned int i = 0; i < b.size(); i++) {
			b[i] = i * 10;
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		}

		std::cout << "\nTest de la copie :" << std::endl;
		Array<int> c(b);
		std::cout << "Taille de c (copie) : " << c.size() << std::endl;
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << "c[" << i << "] = " << c[i] << std::endl;

		std::cout << "\n Modifier c sans toucher à b" << std::endl;
		c[0] = 999;
		std::cout << "c[0] = " << c[0] << " | b[0] = " << b[0] << std::endl;

		std::cout << "\nTest de l’opérateur d’affectation :" << std::endl;
		Array<int> d;
		d = b;
		std::cout << "Taille de d = " << d.size() << std::endl;
		std::cout << "d[1] = " << d[1] << " | b[1] = " << b[1] << std::endl;

		std::cout << "\nTest de const :" << std::endl;
		const Array<int> e(b);
		std::cout << "e[2] = " << e[2] << std::endl;
		std::cout << "\nTentative d’affectation à d[1] = b[2]..." << std::endl;
		std::cout << "d[1] = " << d[1] << std::endl;
		d[1] = b[2];
		std::cout << "d[1] = " << d[1] << std::endl;
		std::cout << "\nTest d’accès hors limites :" << std::endl;
		std::cout << "Tentative d’accès à b[10]..." << std::endl;
		std::cout << b[10] << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}
	return 0;
}
