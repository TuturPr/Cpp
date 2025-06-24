/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:10:44 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 17:26:10 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	ScavTrap scavtrap("ScavTrap");
	scavtrap.attack("target1");
	scavtrap.takeDamage(3);
	scavtrap.attack("target2");
	scavtrap.takeDamage(5);
	scavtrap.attack("target3");
	scavtrap.beRepaired(5);
	scavtrap.guardGate();
	scavtrap.takeDamage(2);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();

	return 0;
}
