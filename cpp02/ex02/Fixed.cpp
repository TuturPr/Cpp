/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:53:14 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 16:54:13 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(int const raw)
{
	this->value = raw << fractionalBits;
}

Fixed::Fixed(float const raw) {
	this->value = (int)(roundf(raw * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->value = other.value;
	}
	return *this;
}

bool	Fixed::operator>(Fixed other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(Fixed other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator<=(Fixed other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator>=(Fixed other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator==(Fixed other) const
{
	return (this->toFloat() == other.toFloat());
}

Fixed Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->value++;
	return temp;
}

Fixed Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->value--;
	return temp;
}

float Fixed::operator+(Fixed other) const
{
	return this->toFloat() + other.toFloat();
}

float Fixed::operator-(Fixed other) const
{
	return this->toFloat() - other.toFloat();
}

float Fixed::operator*(Fixed other) const
{
	return this->toFloat() * other.toFloat();
}

float Fixed::operator/(Fixed other) const
{
	if (other.toFloat() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return 0;
	}
	return this->toFloat() / other.toFloat();
}

bool Fixed::operator!=(Fixed other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

float Fixed::toFloat() const {
	return (float)(value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return value >> fractionalBits;
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	return (first < second ? first : second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
	return (first < second ? first : second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	return (first > second ? first : second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
	return (first > second ? first : second);
}
