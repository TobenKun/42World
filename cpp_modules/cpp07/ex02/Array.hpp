/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:34:38 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/27 13:49:55 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

template <typename T>
class Array
{
  public:
	Array()
	{
		arr = new T[0];
		n = 0;
	};
	Array(unsigned int n)
	{
		arr = new T[n];
		this->n = n;
	};
	Array(const Array& a)
	{
		arr = new T[a.size()];

		for (unsigned int i = 0; i < a.size(); i++)
		{
			arr[i] = a.arr[i];
		}
	};
	Array& operator=(const Array& a)
	{
		if (this == &a) return (*this);
		delete[] arr;
		arr = new T[a.size()];

		for (unsigned int i = 0; i < a.size(); i++)
		{
			arr[i] = a.arr[i];
		}
		return (*this);
	};
	~Array() { delete[] arr; };

	unsigned int size() const { return (n); };

	T& operator[](unsigned int n)
	{
		if (n >= this->n)
			throw std::exception();
		else
			return arr[n];
	};

  private:
	T*		 arr;
	unsigned n;
};
