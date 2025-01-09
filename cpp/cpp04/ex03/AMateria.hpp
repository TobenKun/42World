/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:20:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 01:08:13 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter;

class AMateria
{
  public:
	AMateria(std::string const& type);
	virtual ~AMateria();

	std::string const& getType() const;	 // returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void	  use(ICharacter& target);

  protected:
	std::string type;

  private:
	AMateria();
	AMateria(const AMateria&);
	AMateria& operator=(const AMateria&);
};
