/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:32:09 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/09 15:08:39 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string name)
{
	setType(name);
}

Weapon::~Weapon()
{

}

const std::string&	Weapon::getType()
{
	return (type);
}

void	::Weapon::setType(const std::string& s)
{
	type = s;
}
