/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:00:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 18:58:05 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
	std::cout << "Dog -> Constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &animal) : Animal(animal)
{
	std::cout << "Dog -> Copy Constructor called" << std::endl;
	brain = new Brain(*animal.brain);
}

Dog &Dog::operator=(const Dog &animal)
{
	if (&animal != this)
	{
		Animal::operator=(animal);	// Animal 클래스 프로퍼티 덮어쓰기
		delete brain;				// 기존 브레인 해제
		brain = new Brain(*animal.brain);  // animal의 브레인 깊은복사 해오기
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog -> Destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const { std::cout << "멍멍" << std::endl; }

void Dog::printIdea(unsigned int index) const
{
	bool			   success = true;
	const std::string &return_val = brain->get_ideas(index, &success);

	if (success == true)
		std::cout << "index[0]: " << return_val << std::endl;
	else
		std::cout << "Error: wrong index" << std::endl;
}

void Dog::set_Idea(unsigned int index, const std::string &string)
{
	bool success = true;

	brain->set_ideas(index, string, success);
	if (success == false) std::cout << "Error: wrong index" << std::endl;
}
