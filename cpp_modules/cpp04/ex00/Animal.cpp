/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:43:05 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:15:35 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "iostream"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal -> Constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	type = animal.type;
	std::cout << "Animal -> Copy Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (&animal != this)
	{
		this->type = animal.type;
	}
	return (*this);
}

Animal::~Animal() { std::cout << "Animal -> Destructor called" << std::endl; }

std::string Animal::getType() const { return (type); }

void Animal::makeSound() const { std::cout << "동물소리" << std::endl; }
