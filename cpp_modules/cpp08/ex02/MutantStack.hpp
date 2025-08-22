/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:07:52 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/13 19:03:52 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T>

class MutantStack : public std::stack<T, std::deque<T> >
{
  public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack() {}
	MutantStack(const MutantStack& m) : std::stack<T, std::deque<T> >(m) {}
	MutantStack& operator=(const MutantStack& m)
	{
		if (this != &m) std::stack<T, std::deque<T> >::operator=(m);
		return (*this);
	}
	~MutantStack(){};

	iterator begin() { return (this->c.begin()); };
	iterator end() { return (this->c.end()); };

  private:
};
