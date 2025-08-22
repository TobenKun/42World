/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:48:29 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 01:48:48 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
	Cure();
	~Cure();

	AMateria* clone() const;
	void	  use(ICharacter& target);

  private:
	Cure(const Cure&);
	Cure& operator=(const Cure&);
};
