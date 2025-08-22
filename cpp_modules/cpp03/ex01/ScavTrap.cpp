/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:16:06 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/19 09:27:16 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "**ScavTrap constructor called" << std::endl;
	name = "no name";
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "**ScavTrap constructor called" << std::endl;
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "**ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c)
{
	std::cout << "**ScavTrap constructor called" << std::endl;
	name = c.name;
	hit_point = c.hit_point;
	energy_point = c.energy_point;
	attack_damage = c.attack_damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{
	this->name = c.name;
	this->hit_point = c.hit_point;
	this->energy_point = c.energy_point;
	this->attack_damage = c.attack_damage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hit_point < 1 || this->energy_point < 1)
	{
		std::cout << this->name << " CANNOT ATTACK" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target
			  << " causing " << attack_damage << " points of damage!"
			  << std::endl;
	this->energy_point--;
}

void ScavTrap::guardGate()
{
	if (this->hit_point < 1)
	{
		std::cout << this->name << " CANNOT GUARD GATE!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode"
			  << std::endl;
}
