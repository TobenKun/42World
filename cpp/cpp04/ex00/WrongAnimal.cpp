/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:20:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:22:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "iostream"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal -> Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	type = animal.type;
	std::cout << "WrongAnimal -> Copy Constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	if (&animal != this)
	{
		this->type = animal.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal -> Destructor called" << std::endl; }

std::string WrongAnimal::getType() const { return (type); }

void WrongAnimal::makeSound() const { std::cout << "이상한 동물소리" << std::endl; }
