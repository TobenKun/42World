/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:58:34 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:09:35 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat -> Constructor called" << std::endl;
}

Cat::Cat(const Cat &animal)
{
	type = animal.type;
	std::cout << "Cat -> Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &animal)
{
	if (&animal != this)
	{
		this->type = animal.type;
	}
	return (*this);
}

Cat::~Cat() { std::cout << "Cat -> Destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "야옹" << std::endl; }
