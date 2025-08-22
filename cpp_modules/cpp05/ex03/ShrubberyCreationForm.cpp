/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:33:09 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/01 15:40:33 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("no_name", 1, 1)
{
	// there is no target
	// DO NOT USE THIS!
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) :
	AForm(s.getName(), s.getSignGrade(), s.getExecGrade()), target(s.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm&)
{
	// you cannot change target string <-- CONST!!!
	// DO NOT USE THIS!
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// Do nothing..haha
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	this->checkRequirement(executor);

	std::fstream file(target + "_shrubbery", std::ios_base::out);
	std::string	 ascii_tree =
		"                 __/\\__     \n"
		"                 \\ ** /      \n"
		"                 /_**_\\     \n"
		"                 / \\/ \\     \n"
		"               // ^  $ \\\\   \n"
		"             /____________\\  \n"
		"            //  *  %    \\\\^  \n"
		"          ^/ /  @   +  #  \\ \\ \n"
		"         /__/______________\\__\\^\n"
		"        * /  /   +        \\  \\ *\n"
		"       /%  /$ M E R R Y * \\ # \\\n"
		"     ^/____/____o___________\\____\\\n"
		"     * /  ^/            @  \\    \\ *\n"
		"     / %  /C H R I S T M A S\\   # \\\n"
		"  o/^    /o          #   %   \\o    ^\\\n"
		"/_____/_______________________\\______\\\n"
		"*   o   *    o   | * |  o   *    o   *\n"
		"                 |   |\n"
		"                 |___|\n";
	file << ascii_tree;
	if (file.fail()) throw(std::exception());
	file.close();
}
