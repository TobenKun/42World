/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:13:32 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 02:07:21 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource();
	MateriaSource(const MateriaSource&);
	MateriaSource& operator=(const MateriaSource&);
	~MateriaSource();

	void	  learnMateria(AMateria*);
	AMateria* createMateria(std::string const& type);

  private:
	AMateria* skill_list[4];
};

// TODO: 함수 구현 해야됨
//  learnMateria 한거 어떻게 저장해둘지 생각해보기
