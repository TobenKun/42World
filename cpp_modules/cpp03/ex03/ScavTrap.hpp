/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:32:40 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/19 10:07:32 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &);
	virtual ~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};
