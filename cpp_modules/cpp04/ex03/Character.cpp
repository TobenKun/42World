/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:27:33 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/25 16:39:20 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include "AMateria.hpp"

Character::Character()
{
	inventory[0] = 0;
	inventory[1] = 0;
	inventory[2] = 0;
	inventory[3] = 0;

	size = 100;
	lost_spell_count = 0;
	lost_spell = new AMateria*[size]();
	std::cout << "이름 없이 생성은 안됩니다ㅠㅠ " << std::endl;
}

Character::Character(const std::string& name)
{
	inventory[0] = 0;
	inventory[1] = 0;
	inventory[2] = 0;
	inventory[3] = 0;

	size = 100;
	lost_spell_count = 0;
	lost_spell = new AMateria*[size]();
	this->name = name;
	std::cout << "캐릭터 생성자 호출!" << std::endl;
}

Character::Character(const Character& character)
{
	for (int i = 0; i < 4; i++)
	{
		if (character.inventory[i] != 0)
			this->inventory[i] = character.inventory[i]->clone();
		else
			this->inventory[i] = 0;
	}
	this->name = character.name;
	delete[] this->lost_spell;
	size = character.size;
	lost_spell = new AMateria*[character.size]();
	for (unsigned int i = 0; i < character.size; i++)
	{
		if (character.lost_spell[i] != 0)
			lost_spell[i] = character.lost_spell[i]->clone();
	}
	std::cout << "캐릭터 복사 생성자 호출!" << std::endl;
}

Character& Character::operator=(const Character& character)
{
	if (this != &character)
	{
		for (int i = 0; i < 4; i++)
		{
			if (character.inventory[i] != 0)
				this->inventory[i] = character.inventory[i]->clone();
			else
				this->inventory[i] = 0;
		}
		this->name = character.name;
		delete[] this->lost_spell;
		lost_spell = new AMateria*[character.size]();
		for (unsigned int i = 0; i < character.size; i++)
		{
			if (character.lost_spell[i] != 0)
				lost_spell[i] = character.lost_spell[i]->clone();
		}
	}
	std::cout << "캐릭터 대입 생성자 호출!" << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "character destructor called!!!!!!!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
	for (unsigned int i = 0; i < size; i++)
	{
		delete lost_spell[i];
	}
	delete[] lost_spell;
}

std::string const& Character::getName() const { return (name); }

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = m->clone();
			break;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || inventory[idx] == 0) return;

	lost_spell[lost_spell_count++] = inventory[idx];
	if (lost_spell_count == size)
	{
		make_bigger_container();
	}
	inventory[idx] = 0;
}

void Character::make_bigger_container()
{
	AMateria** new_container = new AMateria*[size * 2]();
	for (unsigned int i = 0; i < size; i++)
	{
		new_container[i] = lost_spell[i]->clone();
		delete lost_spell[i];
	}
	delete[] lost_spell;
	lost_spell = new_container;
	size *= 2;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || inventory[idx] == 0) return;
	inventory[idx]->use(target);
}
