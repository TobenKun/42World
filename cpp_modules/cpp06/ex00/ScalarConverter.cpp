/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:55:29 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/21 22:46:09 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& s) { (void)s; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s)
{
	(void)s;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(char* s)
{
	if (s == 0) return;

	char* endptr;
	errno = 0;
	double x = strtod(s, &endptr);

	// NAN 예외처리
	if (std::isnan(x))
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: nanf\n"
				  << "double: nan" << std::endl;
		return;
	}

	// INF 예외 처리
	if (std::isinf(x))
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << ((x > 0) ? "float: +inff\n" : "float: -inff\n")
				  << ((x > 0) ? "double: +inf" : "double: -inf") << std::endl;
		return;
	}

	// 문자 한글자 처리
	if (strlen(s) == 1 && !isdigit(*s))
	{
		x = *s;
		endptr++;
	}

	// 숫자 뒤에 문자가 남아있는 경우, double형 오버플로 예외처리
	if ((*endptr != 0 && *endptr != 'f') ||
		(*endptr == 'f' && *(endptr + 1) != 0) || errno == ERANGE ||
		endptr == s)
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: impossible\n"
				  << "double: impossible" << std::endl;
		return;
	}

	// char 변환
	if (x >= 32 && x <= 126)
		std::cout << "char: " << static_cast<char>(x) << std::endl;
	else if (x > std::numeric_limits<char>::max() ||
			 x < -std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// int 변환
	if (x > std::numeric_limits<int>::max() ||
		x < -std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(x) << std::endl;

	// float 변환
	if (x > std::numeric_limits<float>::max() ||
		x < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else if (x == static_cast<int>(x))
		std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;

	// double 변환
	if (x == static_cast<int>(x))
		std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(x) << std::endl;
}
