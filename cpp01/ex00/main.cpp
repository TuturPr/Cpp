/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:05 by aperceva          #+#    #+#             */
/*   Updated: 2025/09/22 12:34:01 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* zombie1;
	zombie1 = newZombie("Zombie1");
	randomChump("Zombie2");
	zombie1->announce();
	delete zombie1;

	randomChump("Zombie3");

	return 0;
}
