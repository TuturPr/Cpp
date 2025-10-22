/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:12:56 by arthur            #+#    #+#             */
/*   Updated: 2025/10/22 17:20:57 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void    iter(T* array, int length, void (*func)(T&))
{
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void    iter(const T* array, int length, void (*func)(const T&))
{
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void    printElement(T& element)
{
	std::cout << element << '\n';
}
