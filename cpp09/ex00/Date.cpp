/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:03:47 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 12:42:49 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <iostream>

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year)
{
}

Date::Date(const Date& other)
{
	*this = other;
}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		this->_day = other._day;
		this->_month = other._month;
		this->_year = other._year;
	}
	return *this;
}

bool Date::operator<(const Date& other) const
{
	if (this->_year != other._year)
		return this->_year < other._year;
	if (this->_month != other._month)
		return this->_month < other._month;
	return this->_day < other._day;
}

bool Date::operator>(const Date& other) const
{
	if (this->_year != other._year)
		return this->_year > other._year;
	if (this->_month != other._month)
		return this->_month > other._month;
	return this->_day > other._day;
}

bool Date::operator==(const Date& other) const
{
	return this->_day == other._day && this->_month == other._month && this->_year == other._year;
}

bool Date::operator!=(const Date& other) const
{
	if (this->operator==(other))
		return false;
	return true;
}

bool Date::operator<=(const Date& other) const
{
	if (this->operator<(other) || this->operator==(other))
		return true;
	return false;
}

bool Date::operator>=(const Date& other) const
{
	if (this->operator>(other) || this->operator==(other))
		return true;
	return false;
}


int Date::getDay() const
{
	return this->_day;
}

int Date::getMonth() const
{
	return this->_month;
}

int Date::getYear() const
{
	return this->_year;
}

bool Date::checkDate() const
{
	if (this->_year < 0 || this->_month < 1 || this->_month > 12 || this->_day < 1)
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((this->_year % 4 == 0 && this->_year % 100 != 0) || (this->_year % 400 == 0))
		daysInMonth[1] = 29;
	if (this->_day > daysInMonth[this->_month - 1])
		return false;
	return true;
}

Date::~Date()
{
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getYear() << "-";
	if (date.getMonth() < 10)
		os << "0";
	os << date.getMonth() << "-";
	if (date.getDay() < 10)
		os << "0";
	os << date.getDay();
	return os;
}
