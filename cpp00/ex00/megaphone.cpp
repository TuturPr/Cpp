/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:00:39 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/13 14:58:18 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		while (argv[i] != NULL)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << char(std::toupper(argv[i][j]));
				j++;
			}
			i++;
		}
		std::cout << std::endl;
		return (0);
	}
}
