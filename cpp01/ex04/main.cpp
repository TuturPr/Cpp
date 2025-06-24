/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:17 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/24 12:55:04 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replaceStrings(std::ofstream &fileOut, const std::string &s1, const std::string &s2, const std::string &input)
{
	size_t pos = 0;
	size_t found;

	while ((found = input.find(s1, pos)) != std::string::npos)
	{
		fileOut << input.substr(pos, found - pos);
		fileOut << s2;
		pos = found + s1.length();
	}
	fileOut << input.substr(pos) << std::endl;
}


int main(int argc, char ** argv)
{
	std::ifstream	fileIn;
	std::ofstream	fileOut;
	std::string		s1;
	std::string		s2;
	std::string		buff;
	std::string		file;
	std::string		fileReplace;

	if (argc != 4)
		return (1);

	s1 = argv[2];
	s2 = argv[3];

	file = argv[1];
	fileIn.open(file.c_str());
	if (!fileIn.is_open())
	{
		std::cerr << "Error: Could not open file " << file << std::endl;
		return (1);
	}
	else
	{
		fileReplace = file + ".replace";
		fileOut.open(fileReplace.c_str());
		if (!fileOut.is_open())
		{
			std::cerr << "Error: Could not create file " << fileReplace << std::endl;
			return (1);
		}
	}
	while (std::getline(fileIn, buff))
		replaceStrings(fileOut, s1, s2, buff);
	fileIn.close();
	fileOut.close();
	return (0);
}
