/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:17 by aperceva          #+#    #+#             */
/*   Updated: 2025/09/22 15:17:42 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	int n = 5;
	Zombie* horde = zombieHorde(n, "Zombie");
	for (int i = 0; i < n; ++i)
		horde[i].announce();
	delete[] horde;
	return 0;
}
