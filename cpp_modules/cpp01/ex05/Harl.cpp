/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:56:46 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/10 08:48:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
	list[0].level = "DEBUG";
	list[0].func = &Harl::debug;
	list[1].level = "INFO";
	list[1].func = &Harl::info;
	list[2].level = "WARNING";
	list[2].func = &Harl::warning;
	list[3].level = "ERROR";
	list[3].func = &Harl::error;
}

Harl::~Harl()
{

}

void	Harl::debug()
{
	std::cout << "this is debug" << std::endl;
}

void	Harl::info()
{
	std::cout << "this is info" << std::endl;
}

void	Harl::warning()
{
	std::cout << "this is warning" << std::endl;
}

void	Harl::error()
{
	std::cout << "this is error" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;
	int	is_succeed = 0;

	while (i < 4)
	{
		is_succeed |= runWithoutIf(list[i].func, checkLevel(list[i], level));
		i++;
	}
	while (!is_succeed)
	{
		std::cout << level << "?? ARE YOU SERIOUS?" << std::endl;
		return;
	}
}

int	Harl::checkLevel(t_member_func &one, std::string level)
{
	return (one.level == level);
}

int	Harl::runWithoutIf(void (Harl::*func)(void), int ret)
{
	while (ret)
	{
		(this->*func)();
		return (1);
	}
	return (0);
}

