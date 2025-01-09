/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:26:44 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/05 17:34:39 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1;

	std::cout << "정적 할당한 좀비" << std::endl;
	z1.setName("first zombie");
	z1.announce();
	std::cout << std::endl;

	Zombie	*z2;
	std::cout << "동적으로 할당한 좀비" << std::endl;
	z2 = newZombie("second Zombie");
	z2->announce();
	std::cout << std::endl;

	std::cout << "함수 내부에서 정적으로 할당한 좀비" << std::endl;
	randomChump("third zombie");
	std::cout << std::endl;

	delete z2; // Freeing memory that was dynamically allocated.
}
