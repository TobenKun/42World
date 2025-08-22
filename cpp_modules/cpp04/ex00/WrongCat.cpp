/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:24:36 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:25:07 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat -> Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &animal)
{
	type = animal.type;
	std::cout << "WrongCat -> Copy Constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &animal)
{
	if (&animal != this)
	{
		this->type = animal.type;
	}
	return (*this);
}

WrongCat::~WrongCat() { std::cout << "WrongCat -> Destructor called" << std::endl; }

void WrongCat::makeSound() const { std::cout << "애옹" << std::endl; }
