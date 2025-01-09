/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:18:06 by sangshin          #+#    #+#             */
/*   Updated: 2024/12/21 15:47:47 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

double RPN::doRPN(const std::string &input)
{
	std::istringstream stream(input);
	char			   one_char;
	// std::string		   one_tokken;
	std::stack<double> stack;

	while (stream >> one_char)
	{
		if (one_char >= '0' && one_char <= '9')
			stack.push(one_char - '0');
		else if (one_char == '+')
		{
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val1 = stack.top();
			stack.pop();
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val2 = stack.top();
			stack.pop();
			stack.push(val2 + val1);
		}
		else if (one_char == '-')
		{
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val1 = stack.top();
			stack.pop();
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val2 = stack.top();
			stack.pop();
			stack.push(val2 - val1);
		}
		else if (one_char == '*')
		{
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val1 = stack.top();
			stack.pop();
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val2 = stack.top();
			stack.pop();
			stack.push(val2 * val1);
		}
		else if (one_char == '/')
		{
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val1 = stack.top();
			stack.pop();
			if (stack.empty())
			{
				std::cerr << "Error: stack is empty" << std::endl;
				exit(1);
			}
			double val2 = stack.top();
			stack.pop();
			stack.push(val2 / val1);
		}
		else
		{
			std::cerr << "Error: wrong input" << std::endl;
			exit(1);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: wrong input format" << std::endl;
		exit(1);
	}
	return (stack.top());
}
