/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:05:42 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/19 16:43:07 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "**FragTrap constructor called" << std::endl;
	name = "no name";
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "**FragTrap constructor called" << std::endl;
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "**FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &c)
{
	std::cout << "**FragTrap constructor called" << std::endl;
	name = c.name;
	hit_point = c.hit_point;
	energy_point = c.energy_point;
	attack_damage = c.attack_damage;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
	this->name = c.name;
	this->hit_point = c.hit_point;
	this->energy_point = c.energy_point;
	this->attack_damage = c.attack_damage;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (this->hit_point < 1 || this->energy_point < 1)
	{
		std::cout << this->name << " CANNOT ATTACK" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target
			  << " causing " << attack_damage << " points of damage!"
			  << std::endl;
	this->energy_point--;
}

void FragTrap::highFivesGuys()
{
	if (this->hit_point < 1)
	{
		std::cout << this->name << " CANNOT HIGH FIVES" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " requests high fives!"
			  << std::endl;
}
