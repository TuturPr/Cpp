/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:10:49 by aperceva          #+#    #+#             */
/*   Updated: 2025/09/22 12:00:41 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{}

HumanB::~HumanB() {}

void HumanB::attack() const
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " is unarmed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
