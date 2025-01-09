/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:12:40 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 23:13:12 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
  public:
	virtual ~IMateriaSource() {}
	virtual void	  learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const& type) = 0;
};
