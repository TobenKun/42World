/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:34:00 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/01 15:40:28 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("no_name", 1, 1)
{
	// there is no target
	// DO NOT USE THIS!
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& s) :
	AForm(s.getName(), s.getSignGrade(), s.getExecGrade()), target(s.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm&)
{
	// you cannot change target string <-- CONST!!!
	// DO NOT USE THIS!
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// Do nothing..haha
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->checkRequirement(executor);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}
