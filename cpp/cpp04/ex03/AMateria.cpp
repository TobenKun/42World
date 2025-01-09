/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:39:52 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 01:56:36 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& materia)
{
	(void)materia;
	std::cout << "클론 함수를 쓰십쇼 휴먼" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
	(void)materia;
	std::cout << "클론 함수를 쓰십쇼 휴먼" << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const& type) { this->type = type; }

AMateria::~AMateria() {}

std::string const& AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "응애" << std::endl;
}
