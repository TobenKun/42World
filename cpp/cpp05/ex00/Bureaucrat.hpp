/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:08:06 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/23 05:25:28 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

class Bureaucrat
{
  public:
	Bureaucrat(int, const std::string &);
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();

	std::string getName() const;
	int			getGrade() const;
	void		downGrade();
	void		upGrade();

	class GradeTooHighException : public std::exception
	{
	};
	class GradeTooLowException : public std::exception
	{
	};

  private:
	Bureaucrat();
	Bureaucrat		 &operator=(const Bureaucrat &);
	const std::string name;
	int				  grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
