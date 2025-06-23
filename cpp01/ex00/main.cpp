/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:05 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/16 16:30:30 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* zombie1;
	zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete zombie1;

	randomChump("Zombie2");

	return 0;
}
