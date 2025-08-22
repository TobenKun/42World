/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:09:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/19 11:40:22 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"

void print_all(std::fstream& input, std::string& one_line,
			   BitcoinExchange& bit);

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: ac must be 2" << std::endl;
		return (1);
	}

	BitcoinExchange bit("data.csv");
	std::fstream	input(av[1]);
	std::string		one_line;

	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	print_all(input, one_line, bit);
}

void print_all(std::fstream& input, std::string& one_line, BitcoinExchange& bit)
{
	std::getline(input, one_line);

	if (one_line != "date | value")
	{
		std::cerr << "Error: wrong input file form." << std::endl;
		exit(1);
	}
	while (std::getline(input, one_line))
	{
		std::string		  date;
		double			  value;
		std::stringstream ss(one_line);

		if (std::getline(ss, date, '|') && (ss >> value))
		{
			double result = bit.calculateValue(date, value);

			if (result != -1)
				std::cout << date << " => " << value << " = " << result
						  << std::endl;
		}
		else
		{
			std::cerr << "Error: bad input => " << date << std::endl;
		}
	}
}
