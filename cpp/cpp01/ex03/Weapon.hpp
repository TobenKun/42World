/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:28:44 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/09 15:08:06 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
  	private:
		std::string type;

	public:
		Weapon(std::string name);
		~Weapon();
		const std::string &getType();
		void               setType(const std::string &s);
};
