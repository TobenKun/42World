/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:18:02 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/19 16:42:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "**DiamondTrap constructor called" << std::endl;
	this->name = "no name";
	ClapTrap::name = "no name_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const std::string name)
{
	std::cout << "**DiamondTrap constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "**DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &c)
{
	std::cout << "**DiamondTrap constructor called" << std::endl;
	name = c.name;
	ClapTrap::name = name + "_clap_name";
	hit_point = c.hit_point;
	energy_point = c.energy_point;
	attack_damage = c.attack_damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &c)
{
	this->name = c.name;
	this->hit_point = c.hit_point;
	this->energy_point = c.energy_point;
	this->attack_damage = c.attack_damage;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name: " << name << std::endl;
	std::cout << "clap name: " << ClapTrap::name << std::endl;
}
