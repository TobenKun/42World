/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:09:14 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/16 08:05:53 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : value(val << f_bits)
{
	const int max = std::numeric_limits<int>::max();

	std::cout << "Int constructor called" << std::endl;
	if (val >= max >> 8)
		std::cout << "     ****************************" << std::endl 
			<< "     VALUE OVERFLOWED.. BUT IDGAF.." << std::endl
			<< "     ****************************" << std::endl;
}

Fixed::Fixed(const float val) : value(roundf(val * (1 << f_bits)))
{
	const int max = std::numeric_limits<int>::max();
	std::cout << "Float constructor called" << std::endl;
	if (val >= max >> 8)
		std::cout << "     ****************************" << std::endl 
			<< "     VALUE OVERFLOWED.. BUT IDGAF.." << std::endl
			<< "     ****************************" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	value = f.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(value) / (1 << f_bits));
}

int	Fixed::toInt() const
{
	return (value / (1 << f_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (os);
}
