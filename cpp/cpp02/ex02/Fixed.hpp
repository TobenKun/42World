/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:55:32 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/16 18:46:58 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
class Fixed
{
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		bool operator>(const Fixed &) const;
		bool operator<(const Fixed &) const;
		bool operator>=(const Fixed &) const;
		bool operator<=(const Fixed &) const;
		bool operator==(const Fixed &) const;
		bool operator!=(const Fixed &) const;

		Fixed &operator++(); // pre increment
		Fixed &operator--();
		const Fixed operator++(int); // post increment
		const Fixed operator--(int);

		const Fixed operator+(const Fixed &) const;
		const Fixed operator-(const Fixed &) const;
		const Fixed operator*(const Fixed &) const;
		const Fixed operator/(const Fixed &) const;

		static Fixed &min(Fixed &, Fixed &);
		static Fixed &max(Fixed &, Fixed &);
		static const Fixed &min(const Fixed &, const Fixed &);
		static const Fixed &max(const Fixed &, const Fixed &);

	private:
		int					value;
		static const int	f_bits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &);
