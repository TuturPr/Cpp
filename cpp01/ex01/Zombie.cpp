/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:26 by aperceva          #+#    #+#             */
/*   Updated: 2025/09/22 15:19:41 by ariou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie() : name("Zombie")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
}

void Zombie::announce() const
{
	std::cout <<  this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
