/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:39:03 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 20:11:04 by sangshin         ###   ########.fr       */
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
	virtual void set_Idea(unsigned int, const std::string &) = 0;
	virtual void printIdea(unsigned int) const = 0;

  protected:
	std::string type;

  private:
};
