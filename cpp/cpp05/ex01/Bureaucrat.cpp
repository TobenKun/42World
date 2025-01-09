/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:15:24 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/27 15:21:06 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("no_name"), grade(1) {}

Bureaucrat::Bureaucrat(int grade, const std::string& name) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name) { grade = b.grade; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	(void)b;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::upGrade()
{
	if (grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::downGrade()
{
	if (grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade++;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << name << " couldn't sign " << f.getName()
				  << " because grade is not enough." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
