/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:32:25 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 00:53:13 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  public:
	Character(const std::string& name);
	Character(const Character&);
	Character& operator=(const Character&);
	~Character();

	std::string const& getName() const;
	void			   equip(AMateria* m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter& target);

  private:
	Character();  // 이름 없이 생성 제한
	void make_bigger_container();

	AMateria*	 inventory[4];
	AMateria**	 lost_spell;
	unsigned int lost_spell_count;
	unsigned int size;
	std::string	 name;
};
