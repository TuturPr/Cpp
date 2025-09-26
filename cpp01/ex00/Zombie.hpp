/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariou <ariou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:28 by aperceva          #+#    #+#             */
/*   Updated: 2025/09/22 10:24:33 by ariou            ###   ########.fr       */
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
		void announce( void ) const;
	private:
		std::string name;

};


Zombie* newZombie( std::string name );
void randomChump( std::string name );
