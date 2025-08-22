/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:18:12 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 01:03:52 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	Ice();
	~Ice();

	AMateria* clone() const;
	void	  use(ICharacter& target);

  private:
	Ice(const Ice&);
	Ice& operator=(const Ice&);
};
