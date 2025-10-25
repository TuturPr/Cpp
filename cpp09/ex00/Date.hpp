/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:03:01 by arthur            #+#    #+#             */
/*   Updated: 2025/10/24 15:00:46 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Date
{
	private:
		int _day;
		int _month;
		int _year;
	public:
		Date(int day, int month, int year);
		Date(const Date& other);
		~Date();

		Date& operator=(const Date& other);
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator>=(const Date& other) const;

		int getDay() const;
		int getMonth() const;
		int getYear() const;
		bool checkDate() const;

};

std::ostream& operator<<(std::ostream& os, const Date& date);
