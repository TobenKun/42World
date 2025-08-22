/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:20:36 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/17 17:50:16 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
  public:
	ClapTrap();
	ClapTrap(std::string);
	ClapTrap(const ClapTrap &);
	ClapTrap &operator=(const ClapTrap &);
	virtual ~ClapTrap();

	virtual void attack(const std::string &target);
	void		 takeDamage(unsigned int amount);
	void		 beRepaired(unsigned int amount);

  protected:
	std::string name;
	int			hit_point;
	int			energy_point;
	int			attack_damage;
};
