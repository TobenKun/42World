/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:59:43 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/13 17:21:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <vector>

Span::Span(unsigned int n) { this->n = n; }

Span::Span(const Span& s) { this->vec = s.vec; }

Span& Span::operator=(const Span& s)
{
	if (this != &s) this->vec = s.vec;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (vec.size() >= n) throw std::exception();
	vec.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (vec.size() < 2) throw std::exception();
	std::sort(vec.begin(), vec.end());

	int span = vec[1] - vec[0];
	for (unsigned int i = 1; i < vec.size() - 1; i++)
	{
		if (vec[i + 1] - vec[i] < span) span = vec[i + 1] - vec[i];
	}
	return (span);
}

unsigned int Span::longestSpan()
{
	if (vec.size() < 2) throw std::exception();
	std::sort(vec.begin(), vec.end());

	return (vec.back() - vec.front());
}
