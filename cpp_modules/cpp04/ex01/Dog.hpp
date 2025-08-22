/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:01:27 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 18:57:40 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &);
	Dog &operator=(const Dog &);
	~Dog();

	void makeSound() const;
	void set_Idea(unsigned int, const std::string &);
	void printIdea(unsigned int) const;

  private:
	Brain *brain;
};
