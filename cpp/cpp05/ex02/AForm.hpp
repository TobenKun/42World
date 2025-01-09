/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:50:46 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/24 20:38:46 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
  public:
	AForm(const std::string &name, int sign_grade, int exec_grade);
	AForm(const AForm &);
	virtual ~AForm();

	const std::string &getName() const;
	bool			   getIsSigned() const;
	const int		  &getSignGrade() const;
	const int		  &getExecGrade() const;
	void			   beSigned(const Bureaucrat &);
	virtual void	   execute(const Bureaucrat &executor) const = 0;
	void			   checkRequirement(const Bureaucrat &) const;

	class GradeTooHighException : public std::exception
	{
	};
	class GradeTooLowException : public std::exception
	{
	};
	class UnsignedExecuteException : public std::exception
	{
	};

  private:
	const std::string name;
	bool			  is_signed;
	const int		  sign_grade;
	const int		  exec_grade;

	AForm();						  // 사용 제한
	AForm &operator=(const AForm &);  // 사용 제한
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
