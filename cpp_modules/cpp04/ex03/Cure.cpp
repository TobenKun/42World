/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:49:02 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/25 16:40:25 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "응애 나 아기 큐어" << std::endl;
}

Cure::Cure(const Cure& ice) : AMateria("cure")
{
	(void)ice;
	std::cout << "클론 함수를 쓰십쇼 휴먼" << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
	(void)cure;
	std::cout << "클론 함수를 쓰십쇼 휴먼" << std::endl;
	return (*this);
}

Cure::~Cure() { std::cout << "아기 큐어 소멸됨" << std::endl; }

AMateria* Cure::clone() const
{
	std::cout << "아기 아이스 복사!" << std::endl;
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
