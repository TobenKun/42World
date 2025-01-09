/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:00:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:10:19 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog -> Constructor called" << std::endl;
}

Dog::Dog(const Dog &animal)
{
	type = animal.type;
	std::cout << "Dog -> Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &animal)
{
	if (&animal != this)
	{
		this->type = animal.type;
	}
	return (*this);
}

Dog::~Dog() { std::cout << "Dog -> Destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "멍멍" << std::endl; }
