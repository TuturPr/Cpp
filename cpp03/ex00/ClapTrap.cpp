/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:03:47 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 17:16:50 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	if (amount > _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " takes fatal damage!" << std::endl;
		_hitPoints = 0;
		return;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has been killed!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired because it is dead!" << std::endl;
		return;
	}
	if (amount == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired by 0 points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to be repaired!" << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points! Total hit points: " << _hitPoints << std::endl;
}
