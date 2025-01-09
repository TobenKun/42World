/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:51:12 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/25 15:31:03 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "hello brain!!" << std::endl; }

Brain::Brain(const Brain& b)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = b.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& b)
{
	if (this != &b)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = b.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() { std::cout << "bye brain!!" << std::endl; }

const std::string& Brain::get_ideas(unsigned int index, bool* success) const
{
	if (index < 100) return (ideas[index]);

	static const std::string wrong_index = "fuck you";
	*success = false;
	return (wrong_index);
}

void Brain::set_ideas(unsigned int index, const std::string& idea,
					  bool& success)
{
	if (index < 100)
	{
		ideas[index] = idea;
		success = true;
	}
	else
	{
		success = false;
	}
}
