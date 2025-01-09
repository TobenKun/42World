/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:47:15 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/30 15:30:22 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <ostream>
#include <string>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{

}

int	PhoneBook::add()
{
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	pnum;
	std::string	sec;

	std::cout << "first name: ";
	std::getline(std::cin, fname);
	std::cout << "last name: ";
	std::getline(std::cin, lname);
	std::cout << "nickname: ";
	std::getline(std::cin, nname);
	std::cout << "phone number: ";
	std::getline(std::cin, pnum);
	std::cout << "darkest secret: ";
	std::getline(std::cin, sec);

	if (space_checker(fname) || space_checker(lname)
		|| space_checker(nname) || space_checker(pnum)
		|| space_checker(sec))
	{
		std::cout << "contact can’t have empty fields" << std::endl;
		return (1);
	}

	this->book[this->index].set_fname(fname);
	this->book[this->index].set_lname(lname);
	this->book[this->index].set_nname(nname);
	this->book[this->index].set_pnum(pnum);
	this->book[this->index].set_sec(sec);
	this->index++;
	this->index %= 8;
	return (0);
}

void	PhoneBook::search()
{
	std::string	usrInput;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << cuttercal(this->book[i].get_fname()) << "|";
		std::cout << std::setw(10) << cuttercal(this->book[i].get_lname()) << "|";
		std::cout << std::setw(10) << cuttercal(this->book[i].get_nname()) << "|";
		std::cout << std::setw(10) << cuttercal(this->book[i].get_pnum()) << "|";
		std::cout << std::endl;
	}
	std::getline(std::cin, usrInput);
	if (usrInput.length() == 1 && usrInput >= "0" && usrInput <= "7")
		print_info(usrInput[0] - '0');
	else
		std::cout << "wrong input" << std::endl;
		
}

std::string	PhoneBook::cuttercal(const std::string& s) const
{
	std::string	new_s = s.substr(0, 9);

	if (s.length() <= 10)
		return (s);
	return (new_s + ".");
	
}

void	PhoneBook::print_info(int index) const
{
	if (this->book[index].get_fname().empty())
	{
		std::cout << "empty contact" << std::endl;
		return ;
	}
	std::cout << "***** INDEX " << index << " *****" << std::endl;
	std::cout << "first name: " << this->book[index].get_fname() << std::endl;
	std::cout << "last name: " << this->book[index].get_lname() << std::endl;
	std::cout << "nickname: " << this->book[index].get_nname() << std::endl;
	std::cout << "phone number: " << this->book[index].get_pnum() << std::endl;
	std::cout << "darkest secret: " << this->book[index].get_sec() << std::endl;
	std::cout << "******************" << std::endl;
}

int	PhoneBook::space_checker(const std::string& s) const
{
	if (s.empty() || s.find_first_not_of(' '))
		return (1);
	for (std::string::size_type i = 0; i < s.size(); i++)
	{
		if (!std::isprint(static_cast<unsigned char>(s[i])))
			return (1);
	}
	return (0);
}
