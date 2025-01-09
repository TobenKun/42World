/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:58:34 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 18:53:22 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat()
{
	std::cout << "Cat -> Constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &animal) :
	Animal(animal)	// type이 이미 같아서 복사할 필요 없음
{
	std::cout << "Cat -> Copy Constructor called" << std::endl;
	brain = new Brain(*animal.brain);
}

Cat &Cat::operator=(const Cat &animal)
{
	if (&animal != this)
	{
		Animal::operator=(animal);	// Animal 클래스 프로퍼티 덮어쓰기
		delete brain;				// 기존 브레인 해제
		brain = new Brain(*animal.brain);  // animal의 브레인 깊은복사 해오기
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat -> Destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const { std::cout << "야옹" << std::endl; }

void Cat::printIdea(unsigned int index) const
{
	bool			   success = true;
	const std::string &return_val = brain->get_ideas(index, &success);

	if (success == true)
		std::cout << "index[0]: " << return_val << std::endl;
	else
		std::cout << "Error: wrong index" << std::endl;
}

void Cat::set_Idea(unsigned int index, const std::string &string)
{
	bool success = true;

	brain->set_ideas(index, string, success);
	if (success == false) std::cout << "Error: wrong index" << std::endl;
}
