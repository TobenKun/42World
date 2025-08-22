/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:45:53 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/22 18:47:06 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain
{
  public:
	Brain();
	Brain(const Brain &);
	Brain &operator=(const Brain &);
	~Brain();

	const std::string &get_ideas(unsigned int, bool *) const;
	void set_ideas(unsigned int index, const std::string &idea, bool &success);

  private:
	std::string ideas[100];
};
