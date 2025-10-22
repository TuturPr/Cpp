/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:24:47 by arthur            #+#    #+#             */
/*   Updated: 2025/10/22 17:52:52 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
	private :
		T 			*array;
		unsigned int _size;
	public :
		Array() : _size(0)
		{
			this->array = new T[this->_size];
		}

		Array(unsigned int n) : _size(n)
		{
			this->array = new T[this->_size];
		}

		Array(const Array &other) : _size(other._size)
		{
			this->array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->array[i] = other.array[i];
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				if (this->array)
					delete [] this->array;
				this->_size = other._size;
				this->array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->array[i] = other.array[i];
			}
			return (*this);
		}

		~Array()
		{
			if (this->array)
				delete [] this->array;
		}

		T &operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::out_of_range("Array index out of range");
			return this->array[index];
		}

		const T &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Array index out of range");
			return this->array[index];
		}

		unsigned int size() const
		{
			return this->_size;
		}

};
