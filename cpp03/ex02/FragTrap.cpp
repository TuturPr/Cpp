/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:27:58 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 17:30:38 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " spawned." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other) {
	std::cout << "FragTrap " << _name << " copied." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " despawned." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
