/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:29:21 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 21:30:35 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class ICharacter
{
  public:
	virtual ~ICharacter() {}
	virtual std::string const& getName() const = 0;
	virtual void			   equip(AMateria* m) = 0;
	virtual void			   unequip(int idx) = 0;
	virtual void			   use(int idx, ICharacter& target) = 0;
};
