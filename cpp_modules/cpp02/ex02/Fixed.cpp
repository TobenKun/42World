/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:09:14 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/07 13:41:22 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int val) : value(val << f_bits)
{
	const int max = std::numeric_limits<int>::max();

	if (val >= max >> 8)
		std::cout << "     ****************************" << std::endl 
			<< "     VALUE OVERFLOWED.. BUT IDGAF.." << std::endl
			<< "     ****************************" << std::endl;
}

Fixed::Fixed(const float val) : value(roundf(val * (1 << f_bits)))
{
	const int max = std::numeric_limits<int>::max();

	if (val >= max >> 8)
		std::cout << "     ****************************" << std::endl 
			<< "     VALUE OVERFLOWED.. BUT IDGAF.." << std::endl
			<< "     ****************************" << std::endl;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &f)
{
	value = f.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	this->value = rhs.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::getRawBits() const
{
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

bool Fixed::operator>(const Fixed &f) const
{
	if (this->value > f.value)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &f) const
{
	if (this->value < f.value)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &f) const
{
	if (this->value >= f.value)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &f) const
{
	if (this->value <= f.value)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &f) const
{
	if (this->value == f.value)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &f) const
{
	if (this->value != f.value)
		return (true);
	return (false);
}

const Fixed Fixed::operator+(const Fixed &f) const
{
	Fixed	tmp(*this);
	tmp.value += f.value;
	return (tmp);
}

const Fixed Fixed::operator-(const Fixed &f) const
{
	Fixed	tmp(*this);
	tmp.value -= f.value;
	return (tmp);
}

const Fixed Fixed::operator*(const Fixed &f) const
{
	Fixed		tmp(*this);
	long long	tmp_a = this->value;
	long long	tmp_b = f.value;
	long long	result = (tmp_a * tmp_b) >> (this->f_bits);

	tmp.value = result;
	return (tmp);
}

const Fixed Fixed::operator/(const Fixed &f) const
{
	Fixed		tmp(*this);
	long long	tmp_a = this->value << this->f_bits;
	long long	tmp_b = f.value;
	long long	result = (tmp_a / tmp_b);

	tmp.value = result;
	return (tmp);
}

Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->value++;
	return (tmp);
}

const Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->value--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.value < b.value ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.value > b.value ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.value < b.value ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.value > b.value ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
