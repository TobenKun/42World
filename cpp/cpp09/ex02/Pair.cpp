/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:28:11 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/17 05:24:37 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pair.hpp"

int Pair::compare_count = 0;

Pair::Pair(int value, void *pair) : value(value), pair((Pair *)pair) {}

Pair::Pair(const Pair &p) : value(p.value), pair(p.pair) {}

Pair::~Pair() {}

Pair &Pair::operator=(const Pair &p)
{
	if (this != &p)
	{
		value = p.value;
		pair = p.pair;
	}
	return (*this);
}

bool Pair::comp(const Pair &a, const Pair &b)
{
	compare_count++;
	return (a.value > b.value);
}
// 보통 comp 함수는 return (a < b) 이지만 나는 역순으로 정렬하기 때문에 반대임
