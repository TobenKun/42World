/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:58:04 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/24 20:38:24 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <ostream>
#include "Bureaucrat.hpp"

AForm::AForm() : name("NO_NAME"), sign_grade(1), exec_grade(1)
{
	// DO NOT USE THIS CONSTRUCTOR!!
}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade) :
	name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade <= 0 || exec_grade <= 0) throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& f) :
	name(f.name),
	is_signed(f.is_signed),
	sign_grade(f.sign_grade),
	exec_grade(f.exec_grade)
{
	// 이미 생성된거라서 예외처리 불필요
}

AForm& AForm::operator=(const AForm& f)
{
	// const 값들의 변경은 불가능 하기 때문에 사용 금지
	(void)f;
	return (*this);
}

AForm::~AForm()
{
	// DO NOTHING..For now..
}

const std::string& AForm::getName() const { return (name); }

bool AForm::getIsSigned() const { return (is_signed); }

const int& AForm::getSignGrade() const { return (sign_grade); }

const int& AForm::getExecGrade() const { return (exec_grade); }

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > sign_grade) throw GradeTooLowException();
	is_signed = true;
}

void AForm::checkRequirement(const Bureaucrat& executor) const
{
	if (executor.getGrade() > exec_grade) throw GradeTooLowException();
	if (is_signed == false) throw UnsignedExecuteException();
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << b.getName()
	   << "Created, \nGrade required for sign: " << b.getSignGrade()
	   << "\nGrade required for exec: " << b.getExecGrade() << std::endl;
	return (os);
}
