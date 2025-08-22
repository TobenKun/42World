/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:48:54 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/21 22:58:38 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>	// for rand(), srand()
#include <ctime>	// for clock()
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

int main()
{
	Base* tmp = generate();

	identify(*tmp);
	identify(tmp);
	delete tmp;
}

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::clock()));
	int random_int = std::rand();
	if (random_int % 3 == 0)
		return (new A);
	else if (random_int % 3 == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	Base* tmp;

	std::cout << "PTR: ";
	if ((tmp = dynamic_cast<A*>(p)))
		std::cout << "this is A" << std::endl;
	else if ((tmp = dynamic_cast<B*>(p)))
		std::cout << "this is B" << std::endl;
	else
		std::cout << "this is C" << std::endl;
}

void identify(Base& p)
{
	std::cout << "REF: ";
	try
	{
		A& tmp = dynamic_cast<A&>(p);
		std::cout << "this is A" << std::endl;
		(void)tmp;
		return;
	}
	catch (...)
	{
	}
	try
	{
		B& tmp = dynamic_cast<B&>(p);
		std::cout << "this is B" << std::endl;
		(void)tmp;
		return;
	}
	catch (...)
	{
	}
	try
	{
		C& tmp = dynamic_cast<C&>(p);
		std::cout << "this is C" << std::endl;
		(void)tmp;
		return;
	}
	catch (...)
	{
	}
}
