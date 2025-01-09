/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:21:37 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/25 16:40:06 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "응애 나 아기 아이스" << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria("ice")
{
	(void)ice;
	std::cout << "클론 함수를 쓰십쇼 휴먼" << std::endl;
}

Ice& Ice::operator=(const Ice& ice)
{
	(void)ice;
	std::cout << "클론 함수를 쓰십쇼 휴먼" << std::endl;
	return (*this);
}

Ice::~Ice() { std::cout << "아기 아이스 간다.." << std::endl; }

AMateria* Ice::clone() const
{
	std::cout << "아기 아이스 복사!" << std::endl;
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
