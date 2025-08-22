/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:00 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/20 19:52:43 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("one");
	ClapTrap b("two");

	a.attack("sangshin");
	a.takeDamage(5);
	a.takeDamage(4);
	a.attack("sangshin");

	a.beRepaired(10);
	a.attack("hero");
}
