/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:48:48 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/13 17:45:43 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span
{
  public:
	Span(unsigned int);
	Span(const Span&);
	Span& operator=(const Span&);
	~Span();

	void		 addNumber(int);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (vec.size() >= n) throw std::exception();
			vec.push_back(*begin);
			begin++;
		}
	}

  private:
	Span();

	unsigned int	 n;
	std::vector<int> vec;
};
