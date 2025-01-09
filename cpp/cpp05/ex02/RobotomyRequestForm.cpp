/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:08:43 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/01 15:40:19 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("no_name", 1, 1)
{
	// there is no target
	// DO NOT USE THIS!
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) :
	AForm(s.getName(), s.getSignGrade(), s.getExecGrade()), target(s.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&)
{
	// you cannot change target string <-- CONST!!!
	// DO NOT USE THIS!
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// Do nothing..haha
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	this->checkRequirement(executor);

	std::srand(static_cast<unsigned int>(std::time(0)));

	std::cout << "drilling noise..." << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << target << " robotomized failed......" << std::endl;
}
