/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:36:39 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/05 17:44:49 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	arr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		arr[i].setName(name);
	}
	return (arr);
}
