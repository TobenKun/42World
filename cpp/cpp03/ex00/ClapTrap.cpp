/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:20:33 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/17 17:08:02 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
	name("no name"), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) :
	name(name), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "constructor called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "destructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &c) :
	name(c.name),
	hit_point(c.hit_point),
	energy_point(c.energy_point),
	attack_damage(c.attack_damage)
{
	std::cout << "constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	this->name = c.name;
	this->hit_point = c.hit_point;
	this->energy_point = c.energy_point;
	this->attack_damage = c.attack_damage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_point < 1 || this->energy_point < 1)
	{
		std::cout << this->name << " CANNOT ATTACK" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << " causing " << attack_damage << " points of damage!"
			  << std::endl;
	this->energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point < 1)
	{
		std::cout << this->name << " ALREADY DEAD" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount
			  << " points of damage!" << std::endl;
	this->hit_point -= amount;
	if (this->hit_point < 0) this->hit_point = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point < 1 || this->energy_point < 1)
	{
		std::cout << this->name << " CANNOT BE REPAIRED" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount
			  << " of damage" << std::endl;
	this->energy_point--;
	this->hit_point += amount;
}
