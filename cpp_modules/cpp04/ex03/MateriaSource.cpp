/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:17:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/25 16:41:48 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	skill_list[0] = 0;
	skill_list[1] = 0;
	skill_list[2] = 0;
	skill_list[3] = 0;
	std::cout << "소스 생성" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source)
{
	for (int i = 0; i < 4; i++)
	{
		if (source.skill_list[i] != 0)
			skill_list[i] = source.skill_list[i]->clone();
		else
			skill_list[i] = 0;
	}
	std::cout << "소스 복사 생성" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& source)
{
	std::cout << "소스 대입 생성" << std::endl;
	if (this != &source)
	{
		for (int i = 0; i < 4; i++)
		{
			if (source.skill_list[i] != 0)
				skill_list[i] = source.skill_list[i]->clone();
			else
				skill_list[i] = 0;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (skill_list[i] != 0) delete skill_list[i];
	}
	std::cout << "소스 소멸" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (skill_list[i] == 0)
		{
			skill_list[i] = materia->clone();
			break;
		}
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (skill_list[i] != 0 && skill_list[i]->getType() == type)
			return (skill_list[i]->clone());
	}
	return (0);
}
