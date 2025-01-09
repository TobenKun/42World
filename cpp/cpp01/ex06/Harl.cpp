/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:56:46 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/10 09:20:03 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(std::string param)
{
	list[0].level = "DEBUG";
	list[0].func = &Harl::debug;
	list[0].is_on = 0;
	list[1].level = "INFO";
	list[1].func = &Harl::info;
	list[1].is_on = 0;
	list[2].level = "WARNING";
	list[2].func = &Harl::warning;
	list[2].is_on = 0;
	list[3].level = "ERROR";
	list[3].func = &Harl::error;
	list[3].is_on = 0;

	int param_ret = param_check(param);
	switch (param_ret) 
	{
		case DEBUG:
			list[0].is_on = 1;
		case INFO:
			list[1].is_on = 1;
		case WARNING:
			list[2].is_on = 1;
		case ERROR:
			list[3].is_on = 1;
			break;
		case ELSE:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
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
		is_succeed |= runWithoutIf(list[i].func, checkLevel(list[i], level),
							 list[i].is_on);
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

int	Harl::runWithoutIf(void (Harl::*func)(void), int ret, int is_on)
{
	if (is_on == 0)
		return (1);
	while (ret)
	{
		(this->*func)();
		return (1);
	}
	return (0);
}

int	Harl::param_check(std::string param)
{
	if (param == "DEBUG")
		return (DEBUG);
	if (param == "INFO")
		return (INFO);
	if (param == "WARNING")
		return (WARNING);
	if (param == "ERROR")
		return (ERROR);
	return (ELSE);

}
