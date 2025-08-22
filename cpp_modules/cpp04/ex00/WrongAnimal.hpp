/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:19:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:22:53 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"

class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);
	virtual ~WrongAnimal();

	std::string	 getType() const;
	void makeSound() const;

  protected:
	std::string type;

  private:
};
