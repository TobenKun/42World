/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:39:03 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/21 09:04:21 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"

class Animal
{
  public:
	Animal();
	Animal(const Animal &);
	Animal &operator=(const Animal &);
	virtual ~Animal();

	std::string	 getType() const;
	virtual void makeSound() const;

  protected:
	std::string type;

  private:
};
