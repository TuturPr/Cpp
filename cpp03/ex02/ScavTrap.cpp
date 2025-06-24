/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:18:48 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 17:27:08 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " appeared." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copied." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " disappeared." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::guardGate() {
	if (_isGateKeeper) {
		std::cout << "ScavTrap " << _name << " is already in Gate Keeper mode." << std::endl;
		return;
	}
	else
	{
		_isGateKeeper = true;
		std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " punches " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}
