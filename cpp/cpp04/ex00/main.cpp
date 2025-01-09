/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:41:40 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 02:11:40 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check() { system("leaks animal"); }

int main()
{
	atexit(check);
	std::cout << "----- 생성 시작 -----" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n----- 함수 테스트 -----" << std::endl;
	std::cout << j->getType() << "의 울음소리: ";
	j->makeSound();
	std::cout << i->getType() << "의 울음소리: ";
	i->makeSound();	 // will output the cat sound!
	std::cout << meta->getType() << "의 울음소리: ";
	meta->makeSound();

	std::cout << "\n----- 소멸 시작 -----" << std::endl;
	delete j;
	delete i;
	delete meta;

	if (1)
	{
		std::cout << "\n\n***** Wrong Test *****" << std::endl;
		std::cout << "\n----- 생성 시작 -----" << std::endl;
		const WrongAnimal* new_meta = new WrongAnimal();
		const WrongAnimal* k = new WrongCat();

		std::cout << "\n----- 함수 테스트 -----" << std::endl;
		std::cout << new_meta->getType() << "의 울음소리: ";
		new_meta->makeSound();
		std::cout << k->getType() << "의 울음소리: ";
		k->makeSound();	 // will output the cat sound?

		std::cout << "\n----- 소멸 시작 -----" << std::endl;
		delete k;
		delete new_meta;
	}
	return (0);
}
