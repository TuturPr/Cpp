/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:28 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/16 16:25:28 by aperceva         ###   ########.fr       */
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
void randomChump( std::string name );
