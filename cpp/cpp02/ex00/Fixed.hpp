/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:55:32 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/10 14:33:46 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static const int	f_bits = 8;
};
