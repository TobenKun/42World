/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:00 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/19 16:49:15 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap a("one");
		ClapTrap b("two");

		a.attack("sangshin");
		a.takeDamage(5);
		a.takeDamage(4);
		a.attack("sangshin");

		a.beRepaired(10);
		a.beRepaired(10);
		a.attack("hero");

		std::cout << "---- 소멸 시작 ----" << std::endl;
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "여기부터 스캐브 테스트 " << std::endl;

		ScavTrap c("ycho2");
		c.attack("janhan");
		c.takeDamage(5);
		c.guardGate();
		c.beRepaired(3);
		c.takeDamage(200);
		c.guardGate();
		std::cout << "---- 소멸 시작 ----" << std::endl;
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "여기부터 프래그 테스트 " << std::endl;

		FragTrap d("new frag");
		d.attack("janhan");
		d.takeDamage(5);
		d.highFivesGuys();
		std::cout << "---- 소멸 시작 ----" << std::endl;
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "여기부터 다이아 테스트 " << std::endl;

		DiamondTrap d("janhan");
		d.whoAmI();
		d.attack("someone");
		std::cout << "---- 소멸 시작 ----" << std::endl;
	}
}
