/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:50:46 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/24 20:34:27 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form
{
  public:
	Form(const std::string &name, int sign_grade, int exec_grade);
	Form(const Form &);
	~Form();

	const std::string &getName() const;
	bool			   getIsSigned() const;
	const int		  &getSignGrade() const;
	const int		  &getExecGrade() const;
	void			   beSigned(const Bureaucrat &);

	class GradeTooHighException : public std::exception
	{
	};
	class GradeTooLowException : public std::exception
	{
	};

  private:
	const std::string name;
	bool			  is_signed;
	const int		  sign_grade;
	const int		  exec_grade;

	Form();							// 사용 제한
	Form &operator=(const Form &);	// 사용 제한
};

std::ostream &operator<<(std::ostream &os, const Form &f);
