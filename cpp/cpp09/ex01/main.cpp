/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:09:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/12/21 15:47:08 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
	std::string formula;
	av++;
	while (--ac)
	{
		formula += *av;
		av++;
	}
	std::cout << RPN::doRPN(formula) << std::endl;
}
