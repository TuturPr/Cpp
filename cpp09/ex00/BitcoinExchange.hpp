/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:32:37 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 17:15:14 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float> _dataBase;
		BitcoinExchange();
	public:
		BitcoinExchange(std::string input);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool _open(const std::string str, bool is_input);
		void fillDB(std::string input);
		Date _getDate(std::string date);
		void exchange(std::string input);
};



