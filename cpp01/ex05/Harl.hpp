/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:10:25 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 13:40:24 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	public	:
		Harl();
		~Harl();
		void complain(const std::string &level);

	private	:

		void debug() const;
		void info() const;
		void warning() const;
		void error() const;
};
