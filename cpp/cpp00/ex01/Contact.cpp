/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:43:22 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/03 14:46:39 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::set_fname(std::string s)
{
	this->_firstName = s;
}

void	Contact::set_lname(std::string s)
{
	this->_lastName = s;
}

void	Contact::set_nname(std::string s)
{
	this->_nickname = s;
}

void	Contact::set_pnum(std::string s)
{
	this->_phoneNumber = s;
}

void	Contact::set_sec(std::string s)
{
	this->_secret = s;
}

std::string	Contact::get_fname(void) const
{
	return (this->_firstName);
}

std::string	Contact::get_lname(void) const
{
	return (this->_lastName);
}

std::string	Contact::get_nname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_pnum(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::get_sec(void) const
{
	return (this->_secret);
}
