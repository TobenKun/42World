/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:05:28 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/03 14:53:40 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include "AForm.hpp"

class Intern
{
  public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	AForm* makeForm(std::string form, std::string target);

	class FormNameInvalidException : public std::exception
	{
	};

  private:
	AForm* makeShrubbery(std::string&);
	AForm* makeRobotomy(std::string&);
	AForm* makePresidential(std::string&);
};
