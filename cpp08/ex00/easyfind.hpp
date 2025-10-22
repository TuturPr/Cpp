/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:49:58 by arthur            #+#    #+#             */
/*   Updated: 2025/10/22 20:57:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename T>
int easyfind(T const &array, int b)
{
	typename T::const_iterator it = std::find(array.begin(), array.end(), b);
	if (it == array.end())
		throw std::runtime_error("Element not found");
	return *it;
}


