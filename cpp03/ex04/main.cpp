/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:10:44 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 17:31:10 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap fragtrap("FragTrap");
	fragtrap.attack("target1");
	fragtrap.takeDamage(3);
	fragtrap.attack("target2");
	fragtrap.takeDamage(5);
	fragtrap.attack("target3");
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();


	return 0;
}
