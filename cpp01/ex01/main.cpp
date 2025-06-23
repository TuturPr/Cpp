/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:17 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/21 16:47:15 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* horde = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; ++i)
		horde[i].announce();
	delete[] horde;
	return 0;
}
