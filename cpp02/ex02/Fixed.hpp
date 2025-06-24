/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:53:12 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 16:52:47 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(int const raw);
		Fixed(float const raw);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);
		float operator=(Fixed other) const;
		float operator+(Fixed other) const;
		float operator-(Fixed other) const;
		float operator*(Fixed other) const;
		float operator/(Fixed other) const;
		bool operator<(Fixed other) const;
		bool operator>(Fixed other) const;
		bool operator<=(Fixed other) const;
		bool operator>=(Fixed other) const;
		bool operator==(Fixed other) const;
		bool operator!=(Fixed other) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

