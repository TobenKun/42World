/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:43:03 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/21 22:56:46 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"

#ifndef UINTPTR_MAX
typedef unsigned long uintptr_t;
#endif

class Serializer
{
  public:
	static uintptr_t serialize(Data* ptr);
	static Data*	 deserialize(uintptr_t raw);

  private:
	Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
	~Serializer();
};
