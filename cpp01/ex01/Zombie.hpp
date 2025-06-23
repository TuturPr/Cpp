/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:28 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/21 16:42:28 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce() const;
	private:
		std::string name;

};


Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );
