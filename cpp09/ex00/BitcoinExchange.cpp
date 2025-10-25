/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:32:39 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 17:15:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
# define CSV "data.csv"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string input)
{
	if (_open(CSV, false))
		throw std::runtime_error("Invalid CSV");
	if (_open(input, true))
		throw std::runtime_error("Invalid input file");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_dataBase = other._dataBase;
}

BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_dataBase = other._dataBase;
	}
	return *this;
}

Date BitcoinExchange::_getDate(std::string date)
{
	int day;
	int month;
	int year;
	char sep1, sep2;
	std::istringstream ss(date);
	ss >> year >> sep1 >> month >> sep2 >> day;
	if (ss.fail() || sep1 != '-' || sep2 != '-')
		throw std::runtime_error("Invalid date format: " + date);
	return Date(day, month, year);
}

void BitcoinExchange::fillDB(std::string input)
{
	float value;
	try
	{
		if(input.find(',') == std::string::npos)
			throw std::runtime_error("Invalid line: " + input);
		value = std::atof(input.substr(input.find_first_of(',') + 1, input.length()).c_str());
		this->_dataBase[_getDate(input.substr(0, input.find_first_of(',')))] = value;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void BitcoinExchange::exchange(std::string input)
{
	try
	{
		size_t sep;
		float value;
		float number;

		sep = input.find('|');
		if(sep == std::string::npos)
			throw std::runtime_error("Invalid line: " + input);
		Date date = _getDate(input.substr(0, sep - 1));
		if (!date.checkDate())
			throw std::runtime_error("Invalid date: " + input.substr(0, sep - 1));
		std::map<Date, float>::iterator it = this->_dataBase.find(date);
		if (it == this->_dataBase.end())
		{
			it = this->_dataBase.begin();;
			while (it != this->_dataBase.end() && it->first < date)
				++it;
			if (it == this->_dataBase.begin())
				throw std::runtime_error("No exchange rate available for date: " + input.substr(0, sep - 1));
			--it;

		}
		Date key = it->first;
		number = std::atof(input.substr(sep + 2, input.length()).c_str());
		if (number < 0)
			throw std::runtime_error("Negative number: " + input.substr(sep + 2, input.length()));
		if (number > 1000)
			throw std::runtime_error("Number too large: " + input.substr(sep + 2, input.length()));
		value = number * this->_dataBase[key];
		std::cout << date << " => " << number << " = " << value << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

bool BitcoinExchange::_open(const std::string str, bool is_input)
{
	try
	{
		std::ifstream file(str.c_str());
		if (!file.is_open())
			return (1);
		std::string line;
		while (std::getline(file, line))
		{
			if (line.empty() || line == "date,exchange_rate" || line == "date | value")
				continue;
			if (is_input)
				exchange(line);
			else
				fillDB(line);
		}
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
