/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:00:02 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/18 14:00:18 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange(const std::string& file_name)
{
	std::string	 one_line;
	std::fstream data_file(file_name, std::ios_base::in);
	if (!data_file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	while (std::getline(data_file, one_line))
	{
		std::string		  date;
		double			  value;
		std::stringstream ss(one_line);

		if (std::getline(ss, date, ',') && (ss >> value))
			price_data.insert(std::make_pair(date, value));
	}
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::calculateValue(const std::string& input_date,
									   double			  quantity)
{
	if (checkInput(input_date, quantity)) return (-1);
	std::string closest_date = findClosestDate(input_date);

	return (quantity * getPriceByDate(findClosestDate(input_date)));
}

const std::string& BitcoinExchange::findClosestDate(const std::string& date)
{
	// map에서 date 이상의 첫 번째 날짜를 찾음
	// lower_bound를 만족하는 원소가 없으면 last 리턴해줌
	std::map<std::string, double>::iterator it = price_data.lower_bound(date);

	// 정확히 해당 날짜가 있는 경우 바로 리턴
	if (it != price_data.end() && it->first == date)
	{
		return (it->first);
	}

	// 해당 날짜가 없다면 직전 날짜로
	if (it != price_data.begin()) --it;

	return (it->first);
	// 마지막 데이터를 넘는 경우에는 직전의 마지막 값을 리턴
}

double BitcoinExchange::getPriceByDate(const std::string& date)
{
	return (price_data[date]);
}

int BitcoinExchange::checkInput(const std::string& date, double q)
{
	std::stringstream ss(date);
	std::string		  year;
	std::string		  month;
	std::string		  day;

	if (q < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return (1);
	}
	if (q > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return (1);
	}
	if (!std::getline(ss, year, '-') || !std::getline(ss, month, '-') ||
		!(ss >> day))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (1);
	}
	if ((atoi(month.c_str()) > 12) || (atoi(month.c_str()) > 31))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (1);
	}
	if (date < price_data.begin()->first)  // 첫 날짜 보다 이른 날짜면
	{
		std::cerr << "Error: No price data available for dates earlier than "
				  << price_data.begin()->first << ". Provided date: " << date
				  << std::endl;
		return (1);
	}
	return (0);
}

void BitcoinExchange::printValue()
{
	std::map<std::string, double>::iterator it;

	for (it = price_data.begin(); it != price_data.end(); it++)
		std::cout << it->first << ": " << std::fixed << std::setprecision(2)
				  << it->second << std::endl;
}
