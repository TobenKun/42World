/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:41:40 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 02:12:10 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void check() { system("leaks animal"); }

int main()
{
	int test_mode = 0;
	if (test_mode == 0)
	{
		atexit(check);
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << i->getType() << std::endl;
		std::cout << j->getType() << std::endl;

		delete j;  // should not create a leak
		delete i;

		return (0);
	}
	else if (test_mode == 1)
	{
		atexit(check);

		// 원본 객체 생성
		std::cout << "\n##### 원본 객체 생성 #####" << std::endl;
		const Animal* originalCat = new Cat();
		const Animal* originalDog = new Dog();

		// 복사 생성자 테스트
		std::cout << "\n##### 복사 생성자 테스트 #####" << std::endl;
		Animal* copiedCat = new Cat(*dynamic_cast<const Cat*>(originalCat));
		Animal* copiedDog = new Dog(*dynamic_cast<const Dog*>(originalDog));

		// 복사 대입 연산자 테스트
		std::cout << "\n##### 복사 대입 연산자 테스트 #####" << std::endl;
		Animal* assignedCat = new Cat();
		Animal* assignedDog = new Dog();
		*assignedCat = *dynamic_cast<const Cat*>(originalCat);
		*assignedDog = *dynamic_cast<const Dog*>(originalDog);

		// 타입 출력
		std::cout << "\n##### 타입 출력 #####" << std::endl;
		std::cout << "Original Cat Type: " << originalCat->getType()
				  << std::endl;
		std::cout << "Copied Cat Type: " << copiedCat->getType() << std::endl;
		std::cout << "Assigned Cat Type: " << assignedCat->getType()
				  << std::endl;

		std::cout << "Original Dog Type: " << originalDog->getType()
				  << std::endl;
		std::cout << "Copied Dog Type: " << copiedDog->getType() << std::endl;
		std::cout << "Assigned Dog Type: " << assignedDog->getType()
				  << std::endl;

		// 복사된 객체의 뇌를 수정
		dynamic_cast<Cat*>(copiedCat)->set_Idea(0, "cat->modified");
		dynamic_cast<Dog*>(assignedDog)->set_Idea(0, "dog->modified");

		// 원본 객체와 복사된 객체의 뇌 비교
		std::cout << "\n##### 뇌 비교 #####" << std::endl;
		std::cout << "Original Cat's First Idea: ";
		dynamic_cast<const Cat*>(originalCat)->printIdea(0);
		std::cout << "Copied Cat's First Idea: ";
		dynamic_cast<const Cat*>(copiedCat)->printIdea(0);
		std::cout << std::endl;

		dynamic_cast<const Dog*>(originalDog)->printIdea(0);
		dynamic_cast<const Dog*>(assignedDog)->printIdea(0);

		// 메모리 해제
		std::cout << "\n##### 메모리 해제 #####" << std::endl;
		delete originalCat;
		delete originalDog;
		delete copiedCat;
		delete copiedDog;
		delete assignedCat;
		delete assignedDog;

		return (0);
	}

	else
	{
		atexit(check);

		// Animal 배열 생성
		Animal* animals[10];

		// 배열의 각 원소를 Cat 또는 Dog로 초기화
		for (int i = 0; i < 10; ++i)
		{
			if (i < 5)
			{
				animals[i] = new Cat();
			}
			else
			{
				animals[i] = new Dog();
			}
		}

		// 복사 생성자 테스트
		std::cout << "\n##### 복사 생성자 테스트 #####" << std::endl;
		Animal* copiedAnimals[10];
		for (int i = 0; i < 10; ++i)
		{
			if (i < 5)
			{
				copiedAnimals[i] =
					new Cat(*dynamic_cast<const Cat*>(animals[i]));
			}
			else
			{
				copiedAnimals[i] =
					new Dog(*dynamic_cast<const Dog*>(animals[i]));
			}
		}

		// 복사 대입 연산자 테스트
		std::cout << "\n##### 복사 대입 연산자 테스트 #####" << std::endl;
		Animal* assignedAnimals[10];
		for (int i = 0; i < 10; ++i)
		{
			if (i < 5)
			{
				assignedAnimals[i] = new Cat();
				*assignedAnimals[i] = *dynamic_cast<const Cat*>(animals[i]);
			}
			else
			{
				assignedAnimals[i] = new Dog();
				*assignedAnimals[i] = *dynamic_cast<const Dog*>(animals[i]);
			}
		}
		// 원본 객체의 뇌 수정
		for (int i = 0; i < 10; ++i)
		{
			animals[i]->set_Idea(0, "modified!");
		}
		// 원본 객체와 복사된 객체의 뇌 비교
		std::cout << "\n##### 뇌 비교 #####" << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			std::cout << "Original Animal " << i << " First Idea: ";
			animals[i]->printIdea(0);
			std::cout << "Copied Animal " << i << " First Idea: ";
			copiedAnimals[i]->printIdea(0);
			std::cout << "Assigned Animal " << i << " First Idea: ";
			assignedAnimals[i]->printIdea(0);
		}

		// 메모리 해제
		std::cout << "\n##### 메모리 해제 #####" << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			delete animals[i];
			delete copiedAnimals[i];
			delete assignedAnimals[i];
		}

		return (0);
	}
}
