/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:08:44 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/03 15:02:22 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) { return (*this); }

Intern::~Intern() {}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string form_name[3] = {"shrubbery creation", "robotomy request",
								"presidential pardon"};
	AForm* (Intern::*func_list[3])(std::string&) = {&Intern::makeShrubbery,
													&Intern::makeRobotomy,
													&Intern::makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (form_name[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*func_list[i])(target));
		}
	}

	throw FormNameInvalidException();
	return (0);
}

AForm* Intern::makeShrubbery(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(std::string& target)
{
	return (new PresidentialPardonForm(target));
}
