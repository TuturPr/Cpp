/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:58:04 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/21 17:03:02 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("default") {}

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

std::string const &Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
