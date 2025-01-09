/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:58:04 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/24 20:37:35 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <ostream>

Form::Form() : name("NO_NAME"), sign_grade(1), exec_grade(1)
{
	// DO NOT USE THIS CONSTRUCTOR!!
}

Form::Form(const std::string& name, int sign_grade, int exec_grade) :
	name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade <= 0 || exec_grade <= 0) throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150) throw GradeTooLowException();
}

Form::Form(const Form& f) :
	name(f.name),
	is_signed(f.is_signed),
	sign_grade(f.sign_grade),
	exec_grade(f.exec_grade)
{
	// 이미 생성된거라서 예외처리 불필요
}

Form& Form::operator=(const Form& f)
{
	// const 값들의 변경은 불가능 하기 때문에 사용 금지
	(void)f;
	return (*this);
}

Form::~Form()
{
	// DO NOTHING..For now..
}

const std::string& Form::getName() const { return (name); }

bool Form::getIsSigned() const { return (is_signed); }

const int& Form::getSignGrade() const { return (sign_grade); }

const int& Form::getExecGrade() const { return (exec_grade); }

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > sign_grade) throw GradeTooLowException();
	is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName()
	   << "Created, \nGrade required for sign: " << b.getSignGrade()
	   << "\nGrade required for exec: " << b.getExecGrade() << std::endl;
	return (os);
}
