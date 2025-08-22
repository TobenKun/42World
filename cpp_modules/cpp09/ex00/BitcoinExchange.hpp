/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:51:16 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/18 13:58:37 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
  public:
	BitcoinExchange(const std::string&);
	~BitcoinExchange();

	double calculateValue(const std::string&, double);

	// for debug
	void printValue();

  private:
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);

	const std::string& findClosestDate(const std::string&);
	double			   getPriceByDate(const std::string&);
	int				   checkInput(const std::string&, double);

	std::map<std::string, double> price_data;
};
