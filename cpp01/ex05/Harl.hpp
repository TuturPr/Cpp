/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:10:25 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 13:13:00 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(const std::string &level);
	private:
		void debug();
		void info();
		void warning();
		void error();
};
