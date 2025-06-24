/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:10:44 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 17:21:05 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("ClapTrap");

	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.attack("target2");
	claptrap.takeDamage(5);
	claptrap.attack("target3");
	claptrap.takeDamage(2);
	claptrap.beRepaired(5);
	claptrap.takeDamage(2);
	return 0;
}
