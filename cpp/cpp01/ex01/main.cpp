/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:40:41 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/05 18:03:18 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie* arr;
	int		n = 5;

	arr = zombieHorde(n, "dead bodies");
	for (int i = 0; i < n; i++)
	{
		std::cout << "zombie No." << i << std::endl;
		arr[i].announce();
	}
	delete[] arr;
}
